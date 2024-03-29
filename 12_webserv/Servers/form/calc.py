import sys
import operator

tab = sys.stdin.readline()
nb1 = 0
nb2 = 0
str1 = 0
str2 = 0
op = 0
if (tab):
   str1 = tab.split("&")[0].split("=")[1]
   op = tab.split("&")[1].split("=")[1]
   str2 = tab.split("&")[2].split("=")[1]

if(str1 or str2 or op):
    # print(str1, file=sys.stderr)
    # print(op, file=sys.stderr)
    # print(str2, file=sys.stderr)
    nb1 = str1
    nb2 = str2
    if (op == "%2B"):
       op = operator.add
    elif (op == "-"):
       op = operator.sub
    elif (op == "%2F"):
       op = operator.floordiv
    elif (op == "*"):
       op = operator.mul


body = "<!DOCTYPE html> <html> <head> <title>Calculator</title> </head> <body>"
body += "<div class=\"calc\"style=\"border:1px solid black; border-radius: 25% 10%; align-items: center; display: flex; justify-content: center; flex-direction: column; text-align: center; background-color: grey; width: 300px; height: 300px;\">"
body += "<p style=\"margin-bottom: 40px;\">Welcome to the Extrem Calculator</p>"

body += "<form method=\"post\"> <label for=\"number\">First Number:</label>"
body += "<input type=\"nb1\" class=\"number\" name=\"nb1\"required minlength=\"1\">"
body += "<label for=\"operator\">Operator</label>"
body += "<select name=\"operator\"class=\"operator\">"
body += "<option value=\"+\">+</option>"
body += "<option value=\"-\">-</option>"
body += "<option value=\"/\">/</option>"
body += "<option value=\"*\">*</option> </select>"
body += "<br>"
body += "<label for=\"number\">Second Number</label>"
body += "<input type=\"nb2\" class=\"number\" name=\"nb2\" required minlength=\"1\">"
body += "<input class=\"tryme\" type=\"submit\" value=\"Result\">"
if (not str(str1).lstrip("-").isdigit() or not str(str2).lstrip("-").isdigit()) and tab:
    body += "<p>Give me a digit</p>"
elif (str(str1).lstrip("-").isdigit() or str(str2).lstrip("-").isdigit()) and tab:
    if (int(nb2) == 0 and op == operator.floordiv):
        body += "<p>Can't divide by Zero</p>"
    else:
        res = op(int(nb1), int(nb2))
        body += "<p>" + str(res) + "</p>"
        # print(res, file=sys.stderr)
body += "</divform>"
body += "</div>"
body += "</div>"
body += "</body></html>"
header = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\ncharset=utf-8\r\n"
header += "Content-Length: " + str(len(body)) + "\r\n\r\n"

print (header + body)
nb1 = 0
nb2 = 0
str1 = 0
str2 = 0
op = 0
