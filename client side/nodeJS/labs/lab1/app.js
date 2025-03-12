const http  = require('node:http');
const fs = require('fs');
function returnHtml(status,content,res){
    res.writeHead(status, {'Content-Type': 'text/html'});
    res.end(content+`<a href="/">home</a><a href="/about">about</a><a href="/contact">contact</a>`);
}
function render(status,path,res){
    
    const content = fs.readFileSync(path,'utf-8');
    res.writeHead(status, {'Content-Type': 'text/html'});
    res.end(content);
}
function renderCss(status, path, res)
{
    
    const content = fs.readFileSync(path,'utf-8');
    res.writeHead(status, {'Content-Type': 'text/css'});
    res.end(content);
}
const server = http.createServer(function(req, res)
{
    console.log(req.url);
    let url = req.url.split('?')[0];
    if (url == "/about")
    {
        render(200, 'about.html', res);
    }
    else if (url == '/contact')
    {
        render(200, 'contact.html', res);
    }
    else if (url == '/send')
    {
        render(200, 'done.html', res);
    }
    else if (url == "/style.css")
    {
        renderCss(200, 'style.css', res);
    }
    else
    {
        render(404, "notfound.html", res);
    }
}
)
server.listen(8000);
