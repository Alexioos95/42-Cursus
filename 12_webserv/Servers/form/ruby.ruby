body = "hello World en ruby!"
header = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\ncharset=utf-8\r\n"
header += "Content-Length: #{body.length}\r\n\r\n"
puts header + body
