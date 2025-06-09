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

## Getting Node through WSL
Instructions can be found through an official [Microsoft Guide](https://learn.microsoft.com/en-us/windows/dev-environment/javascript/nodejs-on-wsl)

# Setting Up An Empty Usable Project
You may notice once you run ``` $npm create vite@latest ```, a lot of the files contain pre-written code. If we want a blank state to start out an application: 
1. Go to the root file ``` App.jsx ``` in the src directory.
   - Replace pre-written code with the following code 
     ```
     import './App.css';

     const App = () => {
     return (
          <div className="App">
          </div>
        )
      }
      export default App
     ```

     Note: className is optional but it does make it easier to add CSS this way
2. Style rules included in ``` App.css ``` are applied to all elements and components rendered in the React application.
   - Open the App.css file in the src directory and replace the pre-written code in App.css in the with the following code:
     ```
        #root {
        max-width: 1280px;
        margin: 0 auto;
        padding: 2rem;
        text-align: center;
        font-family: Inter, Avenir, Helvetica, Arial, sans-serif;
        color: black;
        background-color: white;
      }
      
      
       body {
        margin: 0;
        display: flex;
        place-items: center;
        min-width: 320px;
        min-height: 100vh;
      }
     ```
  3. Remove all of the CSS style rules in ``` index.css ```. Add new CSS rules to that file later as needed for the project.
