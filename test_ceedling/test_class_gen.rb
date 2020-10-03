#!/bin/ruby


def replace_in_file(filename, search, replace)
   file_in = File.open(filename, "r")
   contents = file_in.read
   file_in.close

   contents.gsub!(search, replace)

   File.open(filename, "w") do |file|
      file << contents
   end
end


Dir.chdir 'gen_src'

system('ruby ../../ooc_gen.rb new class testbase:TestBase testderived:TestDerived')

# add test code to testbase.c/h {{{
replace_in_file('testbase/testbase.h', '/*- object_context -*/', 'int val;')

replace_in_file('testbase/testbase.c', '/*- ctor -*/', <<-eos
                me->val = 100;
                mytest_supp__checkpoint(CHECKPOINT__BASE_CTOR);
                eos
               )

replace_in_file('testbase/testbase.c', '/*- some_method -*/', <<-eos
                mytest_supp__checkpoint(CHECKPOINT__BASE_SOME_METHOD);
                eos
               )

replace_in_file('testbase/testbase.c', '/*- dtor -*/', <<-eos
                mytest_supp__checkpoint(CHECKPOINT__BASE_DTOR);
                eos
               )

replace_in_file('testbase/testbase.c', '/*- includes -*/', '#include "mytest_support.h"')
# }}}

# add test code to testderived.c/h {{{
replace_in_file('testbase/testderived.h', '/*- object_context -*/', 'int val;')

replace_in_file('testbase/testderived.c', '/*- ctor -*/', <<-eos
                me->val = 100;
                mytest_supp__checkpoint(CHECKPOINT__DERIVED_CTOR);
                eos
               )

replace_in_file('testbase/testderived.c', '/*- some_method -*/', <<-eos
                mytest_supp__checkpoint(CHECKPOINT__DERIVED_SOME_METHOD);
                eos
               )

replace_in_file('testbase/testderived.c', '/*- dtor -*/', <<-eos
                mytest_supp__checkpoint(CHECKPOINT__DERIVED_DTOR);
                eos
               )

replace_in_file('testbase/testderived.c', '/*- includes -*/', '#include "mytest_support.h"')
# }}}

Dir.chdir '..'


