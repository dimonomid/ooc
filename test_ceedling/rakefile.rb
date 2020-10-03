Dir.chdir(File.dirname(__FILE__))

PROJECT_CEEDLING_ROOT = "vendor/ceedling"
load "#{PROJECT_CEEDLING_ROOT}/lib/ceedling.rb"

Ceedling.load_project

task :default => 'test_gen'

task 'test_gen' do

   # generate test classes from templates
   system('ruby test_class_gen.rb')

   # invoke all tests
   Rake::Task['test:all'].invoke
end

