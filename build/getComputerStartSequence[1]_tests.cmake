add_test([=[myfunctions.add]=]  D:/Projects/vscode/backups/MasterMind_Game/build/getComputerStartSequence.exe [==[--gtest_filter=myfunctions.add]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[myfunctions.add]=]  PROPERTIES WORKING_DIRECTORY D:/Projects/vscode/backups/MasterMind_Game/build SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set(  getComputerStartSequence_TESTS myfunctions.add)
