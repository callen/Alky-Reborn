sub ws {
	# whitespace
	s/\r/ /gs;
	s/\n/ /gs;
	s/\t/ /;
	s/  / /gs while(/  /);
	s/; /;/gs;
	s/^ //gs;
}

@_ = <STDIN>;
$_ = join("", @_);

$W = qr/[ \t]*/;
$WR = qr/[ \t]+/;

# Strip out ugly fuckin shit
s/\r/ /gs;

# line escapes
s/\\$W\n//gs;

# preprocessor directives
s/^$W\#.*$//gm;

# comments
s/\/\*.*?\*\///gs;
s/\/\/.*$//gm;

# whitespace
ws;

# externs and namespaces
s/extern.*?\{//gs;
s/namespace.*?\{//gs;

# structs and unions
s/struct[^{}();]+;//gs;

$struct = qr/struct$WR[^;]*\{[^{}]+\}[^;{}]*;/;
$typedef = qr/typedef($WR[^;]+|$W)\{[^{}]+\}[^;{}]*;/;
$union = qr/union$WR[^;]*\{[^{}]+\}[^;{}]*;/;

$rep = 1;
while($rep != 0) {
	$rep =
		($_ =~ s/$struct//gs) +
		($_ =~ s/$typedef//gs) +
		($_ =~ s/$union//gs)
	;
}

# typedefs
s/typedef[^{};]+;//gs;
s/${W}typedef$WR//gs;

# cull out non-prototypes
s/(^|;)[^()]*;/;/gs;
s/\{.*?\}//gs;

# split functions up
ws;
s/;;/;/gs;
my @funcs = split ";", $_;

# parse functions
foreach(@funcs) {
	s/$/;/gs;
	ws;
	
	/^$W(.*?)$WR([a-zA-Z_][a-zA-Z_0-9]*)\((.*?)\);$/;
	
	($ret, $name, $in) = ($1, $2, $3);
	
	$_ = $ret;
	s/^/ /gs;
	s/$/ /gs;
	s/${WR}WINAPI${WR}//gs,s/^/WINAPI /gs if(/WINAPI/);
	s/WIN[A-Z]+API//gs;
	s/WINAPI[A-Z]+//gs;
	s/^ //;
	s/ $//;
	ws;
	$ret = $_;
	
	$_ = $in;
	ws;
	s/^ //;
	s/ $//;
	s/^VOID$//;
	$in = $_;
	
	if(length $name > 0 and length $ret > 0) {
		print "$name\n";
		print "$ret\n";
		print "$in\n";
	}
}
