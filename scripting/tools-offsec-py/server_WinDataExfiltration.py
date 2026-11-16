import http.server
import socketserver
import os
class MyHttpRequestHandler(http.server.SimpleHTTPRequestHandler):
 def do_POST(self):
     content_length = int(self.headers['Content-Length'])
     post_data = self.rfile.read(content_length)
     filename = os.path.basename(self.path) or 'uploaded_file.zip'

     with open(filename, 'wb') as f:
         f.write(post_data)

     self.send_response(200)
     self.end_headers()
     self.wfile.write(b'File uploaded successfully!')
     print(f"\n[+] File received and saved as: {filename}")
PORT = 8000
Handler = MyHttpRequestHandler
with socketserver.TCPServer(("", PORT), Handler) as httpd:
    print(f"[+] Server started on port {PORT}")
    print("[+] Waiting for file upload from Windows client...")
    httpd.serve_forever()
