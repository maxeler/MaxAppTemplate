![Maxeler](https://cloud.githubusercontent.com/assets/3349430/6785679/0d04535a-d17f-11e4-9a57-c3af346a7f95.png)

MaxAppTemplate
==============

This software is all you need to package application source code for the [Maxeler Eco-System](http://appgallery.maxeler.com/).


Installation
------------

MaxAppTemplate uses [cookiecutter](https://github.com/audreyr/cookiecutter) for bootstrapping projects using templates. You can install cookiecutter using the standard Python package managers. The recommended way to install `cookiecutter` is by using `pip`. Please open a `terminal` and type:

    $ [sudo] pip install cookiecutter

However, if you do not have `pip` installed, you can use `easy_install` like so: 

    $ [sudo] easy_install cookiecutter

Usage
-----

Once you have installed `cookiecutter`, simply `cd` to the directory where you want put your new application and type:

    $ cookiecutter https://github.com/alixedi/MaxAppTemplate

`cookiecutter` will cache a copy of the Maxeler app template to the `~/.cookiecutters` directory so that you do not have to download it again. 

This will be followed by an interactive session at the end of which, you will have a Maxler app set-up with the correct directory structure, placeholders for documentation and license as well as skeleton code, ready for uploading to the Maxeler eco-system.

Each question will have a default answer. To use the default answer, simply press `return` without answering it. Following is a brief description of each question:

* **project_name**: Please type the name of the project.
* **project_description**: Please type a short description of the project.
* **author_name**: Please type in your name.
* **author_email**: Please type in a valid email address.
* **dfe_model**: What is the target DFE model for your project? Valid options for this inlcude (TODO)
* **manager_class**: Which manager would you like to employ? Valid options include (TODO)
* **optimize_for_mpcx**: Would you like to optimize the build for MPCX?
* **stem_nae**: Please enter a stem for naming the files and classes in your project. The source code will generated automatically and will work out of the box.
* **slic_interface**: Please specify the SLiC interface that you would like to use. Valid options for this include `basic_static`, `advanced_static` and `dynamic`.

Your applications has been set up and includes skeleton code that should work out of the box. Following is a brief description of some of the sub-directories and files:

* **ORIG**: This directory contains the original CPU implementation of your project with the `make` file to build it like so:


    $ cd ORIG


    $ make

* **SPLIT**: This directory contains the split implementation of your project. The split implementation runs on the CPU. However, the code that will eventually run on the DFE will be separated into a stub function placed in a separate file. The stub function will have the same signature as the DFE implementation, hence forcing you into re-engineer the CPU code to support the new interface. The re-engineering may involve changing the data access patterns to support streaming implementation. Like the original CPU implementation, the split implementationa also comes packaged with the `make` file for building it like so:


    $ cd SPLIT

    $ make
    
* **APP**: This directory contains a valid Maxeler project - including the necessary scaffolding to run out of the box such as skeleton source code, build automation scripts as well as the header files and libraries. Lets try and test if everything is in order by building the simulated version of our project:


    $ cd APP/CPUCode

    $ make --runrule=Simulation
    
* **DOCS**: This directory contains the documentation in [markdown](daringfireball.net/projects/markdown/syntax
) format that is easy to write and compiles to pretty `html`.
* **TESTS**: This directory contains the automated tests for your application. 
* **PLATFORMS**: This directory will contain the compiled binaries and libraries.
* **LICENSE**: What is the license for your code? If you want a release your source code as FOSS, you may benefit from using [Palal](https://github.com/alixedi/palal) - a nifty little tool that will help you choose the right FOSS license.
* **README**: Contains a single page documentation that serves as the title page of your project on GitHub.

Now that we have a fully-functional app, you ready to replace the skeleton source code with your own stuff, write the tests and documentation and upload the project to [GitHub](http://github.com) - A popular service for hosting source code using the [Git](http://git-scm.com) version control system.

You will need to [register](https://help.github.com/articles/signing-up-for-a-new-github-account/) on GitHub first. After which, you will need to [create a new repository](https://help.github.com/articles/creating-a-new-repository/
) and follow the instructions on your repository home page to upload the project to GitHub. 

Generally, these instructions comprise of the following steps:

    $ cd <your_app_directory_root>
    $ git init
    $ git add --all
    $ git commi -m "First Commit"
    $ git remote add origin https://github.com/<your_github_username>/<your_repository_name>.git
    $ git push -u origin master

Enjoy!

How to help
-----------

* If you think this is missing something, please open an issue.

* If you think you can help with some issue, please fork, modify, commit and submit a pull-request.

