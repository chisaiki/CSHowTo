# How to Set Up A Web Dev Environment

## Using Node and Vite
1. Download and install [Node.js](https://nodejs.org/en/download/)
   - To check if Node has been successfully installed: Open Terminal and type: ``` $node --version ```
2. Open the folder you want to launch the website in
3. Open terminal ( Use ctrl + ` ) and type: ``` $npm create vite@latest ```
   -  Name the project 
   - Select React as the framework (use the arrow keys and enter to navigate the menu)
   - Select JavaScript for the language variant
4. Change directory to the new project you named
5. Install the dependencies by running the command: ``` $npm install ```
6. Run the application in developer mode by running the command: ``` $npm run dev ```
7. Open project in the browser. Vite will display a link, such as http://127.0.0.1:5173 to click on or copy/paste that will take you to the localhost port where the project is running.

NOTE: To stop the server, ctrl + c / cmd + c within the Terminal, or use the trash can icon in the top right of the Terminal within VS Code. 
- To run the server again, simply use: ``` $npm run dev ```
