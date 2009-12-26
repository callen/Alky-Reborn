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

@interfaces = split "BEGIN_INTERFACE ";

foreach(@interfaces) {
	if(($decls, $interface) = /^(.*?)END_INTERFACE.*?} (.*?)Vtbl;/) {
		@lines = split ";", $decls;
		my @funcs;
		
		foreach(@lines) {
			if(($ret, $name, $inside) = /^(.*?) \( .*?\*(.*?) \)\( *(.*?) *\)$/gs) {
				$inside =~ s/([ ;])(__in|__out|__in_opt|__inout_opt|__out_opt|__in_ecount_get|__inout|__RPC__deref_out) /$1/gs;
				$inside =~ s/(__(in|out)_[a-z_]+)\(.*?\)//gs;
				$_ = $inside; ws; $inside = $_;
				
				local @temp = ($ret, $name, $inside);
				push @funcs, \@temp;
			}
		}
		
		foreach(@funcs) {
			($ret, $name, $inside) = @$_;
			
			$ret =~ s/^/WINAPI / if(!($ret =~ /WINAPI/));
			
			$inside =~ s/(^| )(I[A-Za-z0-9_]+?) *\*/$1\/* $2 *\/ void */gs;
			$inside =~ s/( |\*)This(,| )/$1this_$2/gs;
			$inside =~ s/( |\*)This$/$1this_/gs;
			
			print "$ret ${interface}_$name($inside);\n";
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
