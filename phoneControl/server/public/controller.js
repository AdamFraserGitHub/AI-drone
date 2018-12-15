const socket = io('/controllerSpace');

function fire1() {
    socket.emit('fire1');
}

function fire2() {
    socket.emit('fire2');
}

function fire3() {
    socket.emit('fire3');
}

function fire4() {
    socket.emit('fire4');
}