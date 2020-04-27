Here is the second challenge for you:  
Topic - GIT

In this challenge, you have to solve two questions.

1. I have made 3 local changes in my test.c(assuming that this is tracked by Git) and I want to discard 1st change and keep other 2nd/3rd changes. Write down appropriate command with proper explanation. 

2. Consider you have made some changes in your working directory. You have staged those changes. How can you see diff of staged changes. Write down appropriate command with proper explanation..  
----------------------------------
Solution:-
Procedure for Task1
Take diff of the changes to a file(known as patch)
$git diff > diff.patch
Revert the file (consider input_0_0/PRU_encoder.c)
$git check input_0_0/PRU_encoder.c
open diff file(diff.patch) and delete the first block which is having your changes (either delete one block or delete lines by updating line numbers)
Apply the patch
$git apply diff.patch

Command for Task2
$git diff --cached
