body = "hello World en python!" . "test error"
header = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\ncharset=utf-8\r\n"
header += "Content-Length: " + str(len(body)) + "\r\n\r\n"
print (header + body)