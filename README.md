![Maxeler](https://cloud.githubusercontent.com/assets/3349430/6785679/0d04535a-d17f-11e4-9a57-c3af346a7f95.png)

MaxAppTemplate
==============

This software has everything you need to package exciting new applications  for the [Maxeler Eco-System](http://appgallery.maxeler.com/).


Installation
------------

###Python

This installation guide will assume that you have `Python` installed on your system. This is a reasonable assumption because these days `Python` comes pre-installed with `Linux` as well as `MacOS`. If you are not sure, open up a `terminal` and type the following:

    $ python -V

If you have `Python` installed on your system, you will get something like:

    Python <version_number>
    
If you do not have `Python` on your system, you can get it for free from the [official website](https://www.python.org/downloads/release/python-279/). I would recommend installing version `2.7.x` because it is supported by a majority of software. Please note that MaxAppTemplate supports all `Python` versions starting from `2.6`. 

###Pip

`Pip` is a package manager for `Python` that comes pre-installed for Python 2.7.9 and later (on the python2 series), and Python 3.4 and later (on the python3 series). If you happen to have a relatively recent version of `Python`, typing `pip` in a `terminal` should give you a standard CLI help text:

    $ pip
    Usage:   
      pip <command> [options]
    ...

If, on the other hand, you get a `command not found` error or something simillar, we need to install `pip`. This is simple enough:

    $ wget https://bootstrap.pypa.io/get-pip.py
    $ [sudo] python get-pip.py

###Cookiecutter

Now that we have sorted out `Python` and `pip`, it is time to install [cookiecutter](https://github.com/audreyr/cookiecutter) - A cool FOSS project for bootstrapping projects from templates. 

The recommended way to install `cookiecutter` is by using `pip`. We will install version 0.9.0 because it supports Python 2.6. Here is how to do it:

    $ [sudo] pip install cookiecutter==0.9.0

If everything has worked, typing `cookiecutter` in your terminal will print:

    $ cookiecutter
    usage: cookiecutter [-h] [--no-input] [-c CHECKOUT] [-V] [-v] input_dir
    cookiecutter: error: too few arguments

Usage
-----

With `cookiecutter` out of our way, simply `cd` to the directory where you want put your new application and type:

    $ cookiecutter https://github.com/alixedi/MaxAppTemplate

If everything goes right, this will kick-off an interactive `Q&A` session. At the end of this `Q&A` session, you will have a Maxler app with the correct directory structure, placeholders for documentation and license as well as working skeleton source code, ready for uploading to the Maxeler eco-system. 

Following is an example `Q&A` session for your reference. Plesae note that each question has a default answer. If you want to go with the default answer, simply press return without typing anything:

1. Name of your project:

        project_name (default is "example_project")? MyProject ↵

2. A brief description of your project:

        project_description (default is "An example project.")? This is an exciting new app. ↵

3. Your name:

        author_name (default is "John Doe")? Ali Zaidi ↵

4. Your email address:

        author_email (default is "jdoe@maxeler.com")? ↵

5. The model of the DFE card that your app supports. Please note that this is just for bootstrapping, later, you can decide to add/change/delete this using MaxIDE. Valid options include `Vectis`, `VectisLite`, `Coria`, `Maia`, `Galava`, `Isca`, `Max2B` and `Max2C`:

        dfe_model (default is "Vectis")? Maia ↵

6. The `KernelManager` type. There are 2 options for this: `Standard` and `Custom`. The former offers simplicity while the latter offer control:

        manager_class (default is "Standard")? ↵
        
7. Whether you would like to turn-on `MPCX` optimizations:

        optimize_for_mpcx (default is "False")? ↵

8. Stem for naming the files, classes, functions etc in your project. For instance, if we select `MyProject` as the `stem_name`, the generated project will have the following naming conventions:

    * Package: `myproject`
    * Kernel class: `MyProjectKernel`
    * EnginerParamters class: `MyProjectEngineParamters`
    * Manager class: `MyProjectManager`
    * Max file: `MyProject`

  Here is the example:
  
        stem_name (default is "ExampleProject")? MyProject ↵

9. SLiC interface type. You will have to choose between `basic_static`, `advanced_static` and `dynamic` in the order of increasing power as well as complexity.

        slic_interaface (default is "basic_static")? advanced_static ↵

At this point, you will see a message like so:

    Generating the project...
    Done.

Your shiny new app with the correct directory structure, placeholders for documentation and license as well as working skeleton source code is now ready for uploading to the Maxeler eco-system. 

App Structure
-------------

Lets look at some of the sub-directories and files in your shiny new app:

###ORIG
This directory contains the original CPU implementation of your project along with the `make` file to build it like so:

    $ cd ORIG
    $ make

###SPLIT
This directory contains the split implementation of your project. The split implementation still runs on the CPU. However, the code that will eventually run on the DFE is identifed and isolated in a function. This function has the same  signature as the DFE implementation. As a result, it forces the re-engineering of the CPU code as well. The re-engineering may involve changing the data access patterns to support streaming implementation. 

Like the original CPU implementation, the split implementationa also comes packaged with the `make` file for building it like so:

    $ cd SPLIT
    $ make
    
###APP
This directory contains a valid Maxeler project that would build and run out of the box like so:

    $ cd APP/CPUCode
    $ make --runrule=Simulation
    
###DOCS
This directory contains the documentation in [markdown](daringfireball.net/projects/markdown/syntax
) format.

###TESTS
This directory contains the automated tests for your application. 

###PLATFORMS
This directory will contain the compiled binaries and libraries.

###LICENSE
If you want to release your source code as FOSS, you may benefit from using [Palal](https://github.com/alixedi/palal) - a nifty little tool that will help you choose the right license.

###README
Contains a single page documentation that serves as the title page of your project on GitHub.


Uploading to GitHub
-------------------
Now that we have a fully-functional app, we can replace the placeholders with our own stuff, write some tests and documentation and upload the project to [GitHub](http://github.com). GitHub is a popular source code hosting service based on  the [Git](http://git-scm.com) version control system. Here is what you need to do:

1. [Register](https://help.github.com/articles/signing-up-for-a-new-github-account/) on GitHub. 
2. [Create a new repository](https://help.github.com/articles/creating-a-new-repository/) 
3. Follow the instructions on your repository home page for uploading the source code. They go something like this:

        $ cd <your_app_directory_root>
        $ git init
        $ git add --all
        $ git commi -m "First Commit"
        $ git remote add origin https://github.com/<your_github_username>/<your_repository_name>.git
        $ git push -u origin master

