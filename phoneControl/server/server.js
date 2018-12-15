//IMPORTS
//====================================================================
//imports express and creates an object from it
var express = require('express');
var app = express();
/* creates a http server and gives express 
 * the ability to controll routing and endpoints of that server 
 */
var server = require('http').Server(app);
/* imports socket.io (websockets library) and tells it to "listen"
 * on the http server we just created
 */
var io = require('socket.io')(server);
const ipModule = require('ip');
const request = require('request');
const path = require('path');
//imports IP module to get server network information
//=====================================================================

app.use('/', express.static('public'));
app.get('/', function(req, res) {
    res.sendFile(path.join(__dirname, 'public', 'controller.html'));
});

var controllSpace = io.of('/controllerSpace');
controllSpace.on('connection', function(socket) {
    console.log("controller connected!");

    socket.on('fire1', function() {
        console.log("fire1");
        sendToDroneServer("1");
    });

    socket.on('fire2', function() {
        console.log("fire2");
        sendToDroneServer("2");
    });

    socket.on('fire3', function() {
        console.log("fire3");
        sendToDroneServer("3");
    });

    socket.on('fire4', function() {
        console.log("fire4");
        sendToDroneServer("4");
    });

    function sendToDroneServer(command) {
        request('http://localhost:5000/postdata', {json: true}, function(err, res, body) {
            if(err) {console.log(err);}
            console.log(body.explaination);
        });

        request.post({
            url:     'http://localhost:5000/postdata',
            body:    "mes=heydude",
            json: {
                "command": command
            }
        }, function(error, response, body){
            console.log(body);
        });
    }
});

server.listen(80,'0.0.0.0', function(err) {
    if(err) {
        console.log("you broke the server! GRRR!! (ノಠ益ಠ)ノ彡┻━┻ \n");
    } else {
        console.log("server started successfully \\(•◡•)/ 💖");
        console.log("IP: " + ipModule.address())
        console.log("port: 80")
        console.log("to connect go to any browser on the same network as\nthis device and type http://" + ipModule.address() + " \nand follow the instructions from there")
    }
})