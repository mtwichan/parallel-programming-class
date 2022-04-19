# Lab 7: CUDA Threads and Kernel Launches

In this lab, you will work on becoming familiar with CUDA threads and kernel launches.  

For this course, we are going to be using Google Colab version and takes advantage of the free Cloud GPUs offered through the platform for CUDA development. Colab Notebooks (you're reading one right now!) are typically designed to run Python code, however, we'll be modifying them in such a way that we can run CUDA code (as discussed in the lectures) on the GPU.  In lab will be completed in a Google COLAB Notebook, which will contain the detailed instructions for the lab activities.  You will need a google account to be able to save a copy of your workbok to your Google Drive but the solutions will be pushed back directly to your repository from Google Colab.  For this lab, you will be working on the file A6.ipynb, located in the lab repository. 

Please note that your code will be written and run directly within this assignment. You will need to save a local copy and ensure that you save and upload your completed Notebook to your GitHub repo for submission. You will also need to provide screenshots of output in many cases for submissions.
**CRITICAL:** Lastly, keep in mind that anytime your runtime disconnects or is restarted you must re-run the Notebook Setup code block. This applies to all CUDA assignments done using Google Colab.

Your solutions to both problems will need to be added to your repository, committed and pushed back upstream to GitHub. Detailed instructions follow. Review the marking rubric to ensure you have addressed all points required for each problem.

**Getting Setup**

0. Since you've got here, you have already successfully accepted and cloned the repository.  You will need to URL of your assignment repo.  
1. Go to http://colab.research.google.com/github
![Connecting Colab and GitHub](/img/colab-setup.png)
    1. On the Colab tab, select *GitHub* (#1)
    2. Ensure that you have selected *Include private repos* (#2) as this will allow Colab access to your private repo for this lab
    3. Enter your GitHub username (or the URL) for your lab repo (#3).  You will have to authenicate Colab and GitHub to allow Colab permission to access your private repo.  
    4.  Select the repo for the lab (#4).  Ensure to use the repo for lab 7.
    5.  Click on the file (#5).  This will open a copy of the file up in Colab.  
2. Once the file is open, save a copy of it to Google Drive (you will need to sign in).  **Rename the file to remove Copy of** (you want to file to have the correct name)
3. Start working in the Colab Notebook.  Make sure to read the instructions in detail as there are specfic steps that need to be done everything you open the Notebook.  
4. Make sure to save your work as you go.  Your code solutions will be entered directly into your notebook.  Just write the code as it you were using a local editor (including all of the required syntax for your programs.

**Saving Your Work Back to GitHub**
When you are done working on your file, you will need to push it back to GitHub, as this is the only way your file will be submitted. 

1. From the File menu in your Colab Notebook, select *File->Save a copy in GitHub*
![Saving Back to GitHub](/img/save-back-to-github.png)
2. Make sure that you select the correct repository.  **Make sure to select *Include a link to Colaboratory*.**. This will create a badge in your Notebook that can be used to automatically re-open the file from GitHub directly into Colab
![Saving Back to GitHub - II](/img/save-back-to-github-II.png)
3. Make sure that you add any additional files and check in your repo to ensure your updated file is there. 

**Accessing Your Work After Your First Commit**
1. Once you've commited your file back to the lab repo with the Colaboratory badge, you can just click on the Badge in GitHub (**Open in Colab**) and the file will be automatically opened for you in Colab to make futher changes.  If you make additional changes, **ensure you save your work and update the file in your repo on Github** using the previously outlined steps.    This will also allow the TAs to run and verify code after submission. 
![Accessing Your File from GitHub After Savings](/img/github-commit.png)

**Lab Details**

**Please utlize the TAs during your specific lab sections with assistance getting this code running.  It is critical that you are able to run this code to be able to complete future GPU labs.**

| **Item**            | **Criteria** |
|----------------|---------------|
|**Assignment:** | Work will be done individually|
|**Assignment Submissions:**| All submissions will be done via GitHub Classroom. **Submit via GitHub**. **Submit only your .ipynb file that contains your c code solutions files as well an any additional files.  Specific questions can be answered directly in the notebook as text (keep separate from code).**|
|**Due Date:**| Electronic submission Friday, November 14th, 2021 – end of day (23:59).  GitHub Classroom is automatically configured to submit your repositories at this time.  Make sure that you have completed the assignment and pushed the changes upstream (back) to your repository.  **While lab 7 isn't due until November 14th, please start early as this will be covered on the midterm exam!**|

**Rubric:** The assignment will be marked as follows:

| **Rubric**                          | **Max Score** | **Value**  |
|-------------------------------------|:-------------:|:----------:|
|*Question 1*                         |               |            |                                                                           
|  Code change generate correct output | /1 |
|  Question answer        | /1  |
|-------------------------------------|-------------|----------|
|*Question 2*                         |               |            |              
| See details in question     |  /18 |  |
|-------------------------------------|-------------|----------|
|*Question 3*                         |               |            |            
| Timing of GPU and CPU operations   | /3| |
| Printing timing   | /1 |  |
| Comments/analysis  | /1 |  |
|*Question 4*                         |               |            |        
| Timing of GPU and CPU operations (without having to recompile (ie using multiple, successive kernel launches with different configurations) | /6 |  |
| Printing timing results | /2 |  |
| Comments/analysis   | /1 |   | 
|-------------------------------------|-------------|----------|
|Total                                |       /34     |            |

Total possible marks 34/34
