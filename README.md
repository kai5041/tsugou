# PRM | A Project Manager for the Command Line

PRM is a tool for developers that helps you manage and collaborate on projects directly from the command line. It simplifies project setup, management, and access, allowing you to handle everything from initialization to collaboration with ease.

What can I do with PRM?
- Create and manage projects: Initialize new projects in different languages and templates.
- Access projects anywhere: Easily manage your projects, whether locally or remotely.
- Create repositories for collaboration: Share and work on projects with others using PRM’s repository functionality.
- Seamless access to repositories: Use various protocols (SSH, HTTP, HTTPS) to access and work with repositories.

## Supported languages
A full list of supported languages can be found [here](example.com). 

## Installation

Before you can start managing your projects, follow these steps to install PRM.

```sh
$ git clone <repo>/prm.git
```

```sh
$ cd prm
```

```sh
$ make install
```
> NOTE: The installation may prompt you for sudo password.

## Usage

### Initialize a new project
To create a new project, you can initialize a directory with a specified template.
Available templates can be found in the [template list](example.com).

```sh
$ prm init <template>
```
> NOTE: If a .prm directory already exists, it will return an error.

### Run a project
You can run your project either locally or remotely.

```sh
$ prm run [project_name]
```

Description: Runs `project_name`, it checks first if the project is in the local directory, otherwise it will run the project saved elsewhere. If just `prm run` is used, it will run the project in the current directory.


# Roadmap

- [ ] Initialize a new project
- [ ] Run a project
