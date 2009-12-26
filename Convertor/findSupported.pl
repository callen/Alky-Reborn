my @funcs;
my $temp;

my @supp;
my @unsupp;

while(<STDIN>) {
    chop;
    /IMPORT\(\".*?\", "(.*?)", 0x.*?\);/;
    push @funcs, $1;
}

foreach(@funcs) {
    $temp = `grep -R "$_" ../LibAlky/Build/`;
    if(length $temp == 0) {
        print;
        print "\n";
    }
}
