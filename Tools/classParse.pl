sub ws {
	# whitespace
	s/[\r\n\t ]+/ /gs;
	s/; /;/gs;
	s/^ //gs;
}

$_ = join "\n", <>;

# preprocessor directives
s/^$W\#.*$//gm;

# comments
s/\/\*.*?\*\///gs;
s/\/\/.*$//gm;

# standardize ws
s/\(/\( /;
s/,/, /;
s/\)/ \)/;
ws;

@interfaces = split "DECLARE_INTER";

foreach(@interfaces) {
	if(($interface, $methods) = /^FACE_?\((.*?)\) *\{ *(.*?) *\};/) {
		if($interface =~ /^(.*?), (.*?)$/) {
			$interface = $1;
		}
		
		@lines = split ";", $methods;
		my @funcs;
		
		foreach(@lines) {
			if(($_, $inside) = /STDMETHOD_?\((.*?)\) *\((.*?)\) PURE/gs) {
				if(!(($ret, $name) = /^(.*?), (.*?)$/)) {
					$ret = 'void';
					$name = $_;
				}
				
				$inside =~ s/THIS_/$interface *this, /;
				$inside =~ s/^THIS$/$interface *this/;
				$inside =~ s/([ ;])(__in|__out|__in_opt|__inout_opt|__out_opt|__in_ecount_get|__inout) /$1/gs;
				$inside =~ s/(__(in|out)_[a-z_]+)\(.*?\)//gs;
				$_ = $inside; ws; $inside = $_;
				
				local @temp = ($ret, $name, $inside);
				push @funcs, \@temp;
			}
		}
		
		foreach(@funcs) {
			($ret, $name, $inside) = @$_;
			
			$ret =~ s/^/WINAPI / if(!($ret =~ /WINAPI/));
			$ret =~ s/(^| )(I[A-Za-z0-9_]+?) *\* */$1\/* $2 *\/ void */gs;
			
			$inside =~ s/(^| )(I[A-Za-z0-9_]+?) *\*/$1\/* $2 *\/ void */gs;
			$inside =~ s/( |\*)This(,| )/$1this_$2/gs;
			$inside =~ s/( |\*)This$/$1this_/gs;
			
			if($ret =~ /\*$/) {
				print "$ret${interface}_$name($inside);\n";
			} else {
				print "$ret ${interface}_$name($inside);\n";
			}
		}
		
		print "\nCLASS(\n";
		print "\t$interface,\n";
		print "\tSTRUCT(),\n";
		
		print "\tVTABLE(\n";
		$str = "";
		foreach(@funcs) {
			($ret, $name, $inside) = @$_;
			
			$str .= "\t\tCSTUB(${interface}_$name),\n";
		}
		$str =~ s/,\n$//;
		print $str, "\n\t)\n);\n\n";
	}
}
