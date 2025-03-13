const express = require('express');
const bodyparser = require('body-parser');

const app = express();
app.use(bodyparser.json());
let cars = [];
app.post(
    '/insertCar',
    function(req, res)
    {
        cars.push(req.body);
        res.send("added car !");
    }
)
app.get(
    '/',
    function(req, res)
    {
        res.sendFile(__dirname+"/index.html");
    }

)
app.get(
    '/getCars',
    function(req, res)
    {
        res.send(cars);
    }
)
app.get(
    '/deleteCar', function(req, res)
    {
        let id = req.query.id;
        let index = cars.findIndex(x=>x.id==id);
        if(index>-1){
            cars.splice(index,1);
            res.send({msg:"deleted"});
        }else{
            res.send({msg:`no such car with id ${id}`});
        }
        }
)
app.post("/edit",function(req,res){
    const id = req.query.id;
    const index = cars.findIndex(x=>x.id==id);
    if(index>-1){
        cars[index] = req.body;
        res.send({msg:"updatd "});
    }else{
        res.send({msg:"no car found with this id "+id});
    }
})
app.get('/find', function(req,res)

{
    const id = req.query.id;
    const index = cars.findIndex(x=>x.id==id);
    if (index > -1)
    {
        res.send({msg:1});
    }
    else res.send({msg:0});
})
app.listen(8000);