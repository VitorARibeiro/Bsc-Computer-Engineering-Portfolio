var canvas = document.createElement('canvas');

canvas.width = window.innerWidth - 15;
canvas.height = window.innerHeight - 100;

var GL = canvas.getContext('webgl');
console.log(GL);
var vertexShader = GL.createShader(GL.VERTEX_SHADER);
var fragmentShader = GL.createShader(GL.FRAGMENT_SHADER);

var program = GL.createProgram();
var gpuArrayBuffer = GL.createBuffer();

function PrepareTriagleData(){

var TriangleArray = [
-0.5, -0.5, 0.0, 1.0, 0.0, 0.0,
0.5, -0.5, 0.0, 0.0, 1.0, 0.0,  
0.0, 0.5, 0.0, 0.0, 0.0, 1.0
];

GL.bindBuffer(GL.ARRAY_BUFFER , gpuArrayBuffer);

GL.bufferData(GL.ARRAY_BUFFER, new Float32Array(TriangleArray), GL.STATIC_DRAW);
}

function SendDataToShaders(){
    var vertexPosition = GL.getAttribLocation(program, 'vertexPosition');
    var vertexColor = GL.getAttribLocation(program, 'vertexColor');

    GL.vertexAttribPointer(vertexPosition, 3, GL.FLOAT, false, 6 * Float32Array.BYTES_PER_ELEMENT, 0);
    GL.vertexAttribPointer(vertexColor, 3, GL.FLOAT, false, 6* Float32Array.BYTES_PER_ELEMENT, 3 * Float32Array.BYTES_PER_ELEMENT);

    GL.enableVertexAttribArray(vertexPosition);
    GL.enableVertexAttribArray(vertexColor);

    GL.useProgram(program);
    GL.drawArrays(GL.TRIANGLES, 0, 3);


}

function PrepareProgram() {
    GL.attachShader(program, vertexShader);
    GL.attachShader(program, fragmentShader);
    GL.linkProgram(program);
    if(!GL.getProgramParameter(program, GL.LINK_STATUS)) {
        console.error('Erro ao linkar o programa', GL.getProgramInfoLog(program));
        return;
    }
    GL.validateProgram(program)
    if(!GL.getProgramParameter(program, GL.VALIDATE_STATUS)) {
        console.error('Erro ao validar o programa', GL.getProgramInfoLog(program));
        return;
    }
    GL.useProgram(program);
}

function PrepareShaders() {
    GL.shaderSource(vertexShader, codigoVertexShader);
    GL.shaderSource(fragmentShader, codigoFragmentShader);

    GL.compileShader(vertexShader);
    GL.compileShader(fragmentShader);

    if(!GL.getShaderParameter(vertexShader, GL.COMPILE_STATUS)) {
        console.error('Erro ao compilar vertex shader', GL.getShaderInfoLog(vertexShader));
        return;
    }

    if(!GL.getShaderParameter(fragmentShader, GL.COMPILE_STATUS)) {
        console.error('Erro ao compilar fragment shader', GL.getShaderInfoLog(fragmentShader));
        return;
    }

}


function PrepareCanvas() {
    GL.clearColor(1, 1, 1, 1.0);

    GL.clear(GL.DEPTH_BUFFER_BIT | GL.COLOR_BUFFER_BIT);
    document.body.appendChild(canvas);

    var mensagem = document.createElement('p');
    mensagem.textContent = 'O canvas encontra-se acima deste texto';
    canvas.insertAdjacentElement('afterend', mensagem);}

function Start() {

    PrepareCanvas();
    PrepareShaders();
    PrepareProgram();
    PrepareTriagleData();
    SendDataToShaders();
}