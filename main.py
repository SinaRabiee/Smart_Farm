from flask import Flask, render_template, request, redirect, url_for
import os


app = Flask("Acurate Afshar App")

@app.route('/')
def main():
    return render_template('index.html')
    # return "<head><title>Afshar</title></head><body><h1>Afshar</h1><p>Welcome to my website</p></body>"

if __name__ == '__main__':
    app.run(host="0.0.0.0", port=5000)