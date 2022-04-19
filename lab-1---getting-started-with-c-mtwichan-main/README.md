# Lab 1 - Introduction to C 

In this lab, you will work on two different C programming challenges in order to become comfortable with standard IO, memory allocation and timing of C code.  These problems can be approached using the Ecliplse IDE in the lab or using on online editor such as https://www.onlinegdb.com. 

Regardless of where you develop and test your code, your solutions to both problems will need to be added to your repository, commited and pushed back upstream to GitHub.  Detailed instructions follow.  Review the marking rubric to ensure you have addressed all points required for each problem.  

| **Item**            | **Criteria** |
|----------------|---------------|
|**Assignment:** | Work will be done individually|
|**Assignment Submissions:**| All submissions will be done via GitHub Classrom. **Submit via GitHub**. **Submit only your .c files (Q1.c and Q2.c) files.**|
|**Due Date:**| Electronic submission Sunday, September 26th, 2021 – end of day (23:59).  GitHub Classroom is automatically configured to submit your repositories at this time.  Make sure that you have completed the assignemnt and pushed the changes upstream (back) to your repository.  **While lab 1 isn't due until the 26th, please start early as you will have a new lab next week!**|

**Rubric:** The assignment will be marked as follows:

| **Rubric**                          | **Max Score** | **Value**  |
|-------------------------------------|:-------------:|:----------:|
|*Question 1*                         |               |            |
|Reading integers                     |       /2      |            |
|Finding sum and avg                  |       /2      |            |
|Counting and printing results        |       /4      |            |
|-------------------------------------|---------------|------------|
|*Question 2*                         |               |            |                                                                
|Creating Arrays                      |       /2      |            |
|Error checking                       |       /2      |            |
|Rest of code                         |       /2      |            |
|Time computation                     |       /2      |            |
|Reporting correct results as a comment|       /4      |            |
|-------------------------------------|---------------|------------|
|Total                                |       /20     |            |

Total possible marks 20/20

**Question 1 (8 marks)**

Write a sequential C code that reads 4 integers from the user and then prints their average along with how many integers are above average.  Save your code as Q1.c.  

The sample runs of your code should look like (user input is the list of numbers entered after the ':' on the first line of each run):

**Sample run 1**

    Enter 4 integers separated by spaces: 1 2 3 10
    There is 1 entry above the average (4.0)

**Sample run 2**
    
    Enter 4 integers separated by spaces: 2 4 7 8
    There are 2 entries above the average (5.3)

Commit your Q1.c file to the lab 1 repository. 

**Question 2 (12 marks)**

Write sequential C code to add 2 vectors `A` and `B` with 

    A[i] = i * 3 
   
and 
  
    B[i] = -i*3 
    
and 

    C[i] = A[i] + B[i]
    
Addtionally, find the sum of all elements in `C`. Eventually, your code should print the `sum` (which is 0) as well as the execution time.  Save your code as Q2.c.

Run your code four times with vector sizes of 1 million, 10 million, 50 million, and 100 million integers. Report the results from these four runs as a comment in the top comment block in your code. 

The sample runs of your code should look like:

**Sample run 1 (successful)**

    Sum: 0 
    Execution time: 0.88 sec

**Sample run 2 (unsuccessful memory allocation)**
    
    Not enough memory.
   
**Notes:** 
* Lookup the function `clock()` from `time.h`.
* Create your arrays using the following syntax `int* R = (int*) malloc(n * sizeof(int))` where `n` is the number of integers in the array `R`. 
* Write code to print the error message if the operating system fails to allocate memory to your arrays, in which case `malloc` will return `NULL`. 

Commit your Q2.c file to the lab 1 repository. 

**Submission Details**

When you are complete with the assignment, ensure all files are added and commited to your repository and that your repository is pushed back upstream to GitHub.  You can @mention your respective TA which will let them know you have completed the assignment.  **You will then submit the URL to your repository via the lab submission link in Canvas.  This link will be used by the TA's to grade your submission**.  **Your submission must be pushed back to the GitHub classroom before the assignment due date and time**.  Your TA's will provide direct feedback (if required), via your repository. 
