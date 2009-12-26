#!/usr/bin/perl -w

use strict;

my $path = '/System/Library/Frameworks/OpenAL.framework/Headers/';
opendir(DIR, $path);
my @files = grep(/\.h$/,readdir(DIR));
closedir(DIR);

my $buffer = '';
foreach my $file (@files) {
   my $file_buffer = '';
   $buffer .= "\n\n".'/* The following functions are declared in '.$file." */\n\n";
   
   open(HEADER_FILE, $path.$file) || die 'Could not open file: '."$file!\n";
   my @file_data = <HEADER_FILE>;
   close(HEADER_FILE);
   foreach my $file_data (@file_data) {
      $file_buffer .= $file_data;
   }

   while ($file_buffer=~/ALC_API (.*?) ALC_APIENTRY (.*?)?\((.*?)\)\;/g) {
      # WINAPI <return> <foo>_(<args>) { NuLog("gl_<foo>"); gl_<foo>(<args>); }
      my ( $return_value, $function_name, $function_args ) = ( $1, $2, $3 );
      my $new_function_args = '';
      
      foreach my $arg (split /,/,$function_args) {
         my @arg_parts = split / /,$arg;
         if ($new_function_args eq '') {
            $new_function_args = $arg_parts[@arg_parts-1];
         } else {
            $new_function_args .= ', '.$arg_parts[@arg_parts-1];
         }
      }

      $new_function_args =~ tr/\*/ /;
      $new_function_args =~ tr/\[.*?\]//;

      $buffer .= <<EOF;
OGL_WRAPPER(
	$return_value,
	$function_name,
	($function_args),
	($new_function_args));
EOF

   }
   
   $buffer .= "\n\n".'/* Parsing of '.$file.' completed. */'."\n\n";
}

print $buffer;

