import tkinter as tk
import os

def isValidContest(fieldsContest):
    if len(fieldsContest) == 4 and fieldsContest[1] == "problem" and fieldsContest[2].isnumeric() and len(fieldsContest[3]) == 1 and fieldsContest[3].isupper():
        return True
    else:
        return False

def isValidGym(fieldsGym):
    if len(fieldsGym) == 4 and fieldsGym[1].isnumeric() and fieldsGym[2] == "problem" and len(fieldsGym[3]) == 1 and fieldsGym[3].isupper():
        return True
    else:
        return False

def parseContest(fields, currentDir):
    if isValidContest(fields):
        roundID = fields[2]
        problem = fields[3]
        contestDir = currentDir + "/contests"
        if (not roundID in os.listdir(contestDir)) or (not problem in os.listdir(contestDir + "/" + roundID)):
            problemDir = contestDir + "/" + roundID + "/" + problem
            os.makedirs(problemDir, exist_ok=True)
            print("Directory created succesfully.")
        else:
            print("Directory already exists.")
    else:
        print("Invalid URL.")

def parseGym(fields, currentDir):
    if isValidGym(fields):
        roundID = fields[1]
        problem = fields[3]
        gymDir = currentDir + "/gym"
        if (not roundID in os.listdir(gymDir)) or (not problem in os.listdir(gymDir + "/" + roundID)):
            problemDir = gymDir + "/" + roundID + "/" + problem
            os.makedirs(problemDir, exist_ok=True)
            print("Directory created succesfully.")
        else:
            print("Directory already exists.")
    else:
        print("Invalid URL.")

def createDir(url):
    urlSplit = url.split("codeforces.com/")
    if len(urlSplit) <= 1:
        print("Invalid URL.")
        return
    fields = urlSplit[1].split("/")
    if fields[0] == "problemset":
        parseContest(fields, os.getcwd())
    elif fields[0] == "gym":
        return parseGym(fields, os.getcwd())
    else:
        print("Invalid URL.")

def submit():
    url = entry.get()
    createDir(url)

window = tk.Tk()
window.title("Codeforces Manager")

entry = tk.Entry(window, width=50)
entry.pack(padx=10, pady=10)

button = tk.Button(window, text="Invia", command=submit)
button.pack(pady=5)

window.mainloop()
