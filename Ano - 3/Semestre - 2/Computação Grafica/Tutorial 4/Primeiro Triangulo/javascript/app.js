var canvas = document.createElement('canvas');

canvas.width = window.innerWidth - 15;
canvas.height = window.innerHeight - 100;

var GL = canvas.getContext('webgl');
console.log(GL);
var vertexShader = GL.createShader(GL.VERTEX_SHADER);
var fragmentShader = GL.createShader(GL.FRAGMENT_SHADER);

var visualizationMatrixLocation;
var projectionMatrixLocation;
var viewportMatrixLocation;

var vertexPosition;
var vertexIndex;
var gpuIndexBuffer = GL.createBuffer();


var program = GL.createProgram();
var gpuArrayBuffer = GL.createBuffer();

var finalMatrixLocation;
var anguloDeRotacao = 0;

function PrepareTriagleData(){

vertexPosition = [
    // x, y, z, r, g, b

    //frente
    0,0,0,0,0,0,
    0,1,0,0,1,0,
    1,1,0,1,1,0,
    1,0,0,1,0,0,

    //direita
    1,0,0,1,0,0,
    1,1,0,1,1,0,
    1,1,1,1,1,1,
    1,0,1,1,0,1,

    //tras
    1,0,1,1,0,1,
    1,1,1,1,1,1,
    0,1,1,0,1,1,
    0,0,1,0,0,1,

    //esquerda
    0,0,1,0,0,1,
    0,1,1,0,1,1,
    0,1,0,0,1,0,
    0,0,0,0,0,0,

    //cima
    0,1,0,0,1,0,
    0,1,1,0,1,1,
    1,1,1,1,1,1,
    1,1,0,1,1,0,

    //baixo
    1,0,0,1,0,0,
    1,0,1,1,0,1,
    0,0,1,0,0,1,
    0,0,0,0,0,0

];

vertexIndex= [
// . Frente
0, 2, 1,
0, 3, 2,

//-Direita
4,6, 5,
4, 7, 6,

// . Trás
8, 10, 9,
8,11,10,

// . Esquerda
12, 14,13,
12, 15,14,

// .Cima
16, 18, 17,
16, 19, 18,

// .Baixo
20, 22, 21,
20, 23, 22
];

GL.bindBuffer(GL.ARRAY_BUFFER , gpuArrayBuffer);

GL.bufferData(GL.ARRAY_BUFFER, new Float32Array(vertexPosition), GL.STATIC_DRAW);

GL.bindBuffer(GL.ELEMENT_ARRAY_BUFFER, gpuIndexBuffer);
GL.bufferData(GL.ELEMENT_ARRAY_BUFFER, new Uint16Array(vertexIndex), GL.STATIC_DRAW);
}

function SendDataToShaders(){
    var vertexPosition = GL.getAttribLocation(program, 'vertexPosition');
    var vertexColor = GL.getAttribLocation(program, 'vertexColor');

    GL.vertexAttribPointer(vertexPosition, 3, GL.FLOAT, false, 6 * Float32Array.BYTES_PER_ELEMENT, 0);
    GL.vertexAttribPointer(vertexColor, 3, GL.FLOAT, false, 6* Float32Array.BYTES_PER_ELEMENT, 3 * Float32Array.BYTES_PER_ELEMENT);

    GL.enableVertexAttribArray(vertexPosition);
    GL.enableVertexAttribArray(vertexColor);

    finalMatrixLocation = GL.getUniformLocation(program, 'transformationMatrix');

    visualizationMatrixLocation = GL.getUniformLocation(program, 'visualizationMatrix');
    projectionMatrixLocation = GL.getUniformLocation(program, 'projectionMatrix');
    viewportMatrixLocation = GL.getUniformLocation(program, 'viewportMatrix');

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
    GL.enable(GL.DEPTH_TEST);
    GL.enable(GL.CULL_FACE);
    document.body.appendChild(canvas);

    var mensagem = document.createElement('p');
    mensagem.textContent = 'O canvas encontra-se acima deste texto';
    canvas.insertAdjacentElement('afterend', mensagem);

}


function loop(){
    canvas.width = window.innerWidth - 15;
    canvas.height = window.innerHeight - 100;
    GL.viewport(0, 0, canvas.width, canvas.height);
    GL.useProgram(program);
    GL.clearColor(1, 1, 1, 1.0);
    GL.clear(GL.DEPTH_BUFFER_BIT | GL.COLOR_BUFFER_BIT);

    var finalMatrix = [
        [1, 0, 0, 0],
        [0, 1, 0, 0],
        [0, 0, 1, 0],
        [0, 0, 0, 1]
    ]

    //finalMatrix = math.multiply(CriarMatrizEscala(0.25,0.25,0.25), finalMatrix);
    finalMatrix = math.multiply(CriarMatrizRotacaoY(anguloDeRotacao), finalMatrix);
    //finalMatrix = math.multiply(CriarMatrizTranslacao(0.5,0.5,0), finalMatrix);

    //finalMatrix = math.multiply(CriarMatrizTranslacao(0,0,1), finalMatrix);
    finalMatrix = math.multiply(CriarMatrizTranslacao(0,0,2), finalMatrix);
    var newarray = [];
    for(var i = 0; i < finalMatrix.length; i++){
        newarray = newarray.concat(finalMatrix[i]);
    }

    var visualizationMatrix = MatrizDeVisualizacao([1,0,0], [0,1,0], [0,0,1], [0,0,0]);
    var newVisualizationMatrix = [];
    for(var i = 0; i < visualizationMatrix.length; i++){
        newVisualizationMatrix = newVisualizationMatrix.concat(visualizationMatrix[i]);
    }

    var projectionMatrix = MatrizPerspectiva(1,4,3,0.1,100);

    var newProjectionMatrix = [];
    for(var i = 0; i < projectionMatrix.length; i++){
        newProjectionMatrix = newProjectionMatrix.concat(projectionMatrix[i]);
    }

    var viewportMatrix = MatrizViewport(-1,1,-1,1);
    var newViewportMatrix = [];
    for(var i = 0; i < viewportMatrix.length; i++){
        newViewportMatrix = newViewportMatrix.concat(viewportMatrix[i]);
    }


    GL.uniformMatrix4fv(finalMatrixLocation, false, newarray);
    GL.uniformMatrix4fv(visualizationMatrixLocation, false, newVisualizationMatrix);
    GL.uniformMatrix4fv(projectionMatrixLocation, false, newProjectionMatrix);
    GL.uniformMatrix4fv(viewportMatrixLocation, false, newViewportMatrix);
    GL.drawElements(GL.TRIANGLES, vertexIndex.length, GL.UNSIGNED_SHORT, 0);

    anguloDeRotacao += 1;
    requestAnimationFrame(loop);
}

function Start() {

    PrepareCanvas();
    PrepareShaders();
    PrepareProgram();
    PrepareTriagleData();
    SendDataToShaders();
    loop();
}