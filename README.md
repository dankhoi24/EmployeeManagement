# Report - EM

$\color{8b94ce}\rule{500px}{2px}$

<aside>
<img src="Report%20-%20EM%20a9bed21a848a4a398e8f652a7229d450/image_2022-07-07_193223429.png" alt="Report%20-%20EM%20a9bed21a848a4a398e8f652a7229d450/image_2022-07-07_193223429.png" width="40px" /> $\text{Table of content}$
[I. Overview](https://www.notion.so/Report-EM-8a4fed8494574d85b6cb6fab5dddd229)
[II. Detail](https://www.notion.so/Report-EM-8a4fed8494574d85b6cb6fab5dddd229)
    [1. Handler](https://www.notion.so/Report-EM-8a4fed8494574d85b6cb6fab5dddd229)
    [2. Printer](https://www.notion.so/Report-EM-8a4fed8494574d85b6cb6fab5dddd229)
    [3. Role](https://www.notion.so/Report-EM-8a4fed8494574d85b6cb6fab5dddd229)    
    [4. Screen](https://www.notion.so/Report-EM-8a4fed8494574d85b6cb6fab5dddd229)

</aside>

## I. Overview

I’ll call Employee Management software is **EM**

Diagram below show dataflow of **EM**

![Untitled](Report%20-%20EM%20a9bed21a848a4a398e8f652a7229d450/Untitled.png)

*Inputer* receive data from user then return to *Handler*, current *Handler* call provided function from *DAO* to handle data and then return to *Printer* to show up to *User .* 

*Inputer* isn’t only responsible for receive data from user but also play a role as a router, *Inputer* receive data from user and specify which *Handler* will handle this information.

## II. Detail

### 1. Handler

EM has many *Handler* corresponding to each Screen to handle request from user to its related screen. When user open a new screen, handler of that screen will be initialize.

![Untitled](Report%20-%20EM%20a9bed21a848a4a398e8f652a7229d450/Untitled%201.png)

Each *handler* has two state: Action and Parameter

Action state - When user chose a option from menu

![Untitled](Report%20-%20EM%20a9bed21a848a4a398e8f652a7229d450/Untitled%202.png)

Parameter state - After user chose a option and **EM** request data from user to execute process

![Untitled](Report%20-%20EM%20a9bed21a848a4a398e8f652a7229d450/Untitled%203.png)

### 2. Printer

After *Handler* done it mission, *Printer* is responsible for show up corresponding screen to user. 

![Untitled](Report%20-%20EM%20a9bed21a848a4a398e8f652a7229d450/Untitled%204.png)

Each Screen has its own file .txt, when **EM** received request from *User* it’ll read file txt of corresponding screen to show up to *User*

![Untitled](Report%20-%20EM%20a9bed21a848a4a398e8f652a7229d450/Untitled%205.png)

### 3. Role

![Untitled](Report%20-%20EM%20a9bed21a848a4a398e8f652a7229d450/Untitled%206.png)

Roles of employee are organize according to hierarchical model but it require flexibility and reusable. So **EM** have to read Role.txt file and store to 2d-vector to present Role.

If you attempt to insert new Role to current model, just insert a new line and fill which role that you want to.

### 4. Screen

Some main screen of **EM**

$\text{Sidebar Screen}$

![Untitled](Report%20-%20EM%20a9bed21a848a4a398e8f652a7229d450/Untitled%202.png)

$\text{View Employee Screen}$

![Untitled](Report%20-%20EM%20a9bed21a848a4a398e8f652a7229d450/Untitled%207.png)

$\text{Add Employee Screen}$

![Untitled](Report%20-%20EM%20a9bed21a848a4a398e8f652a7229d450/Untitled%203.png)