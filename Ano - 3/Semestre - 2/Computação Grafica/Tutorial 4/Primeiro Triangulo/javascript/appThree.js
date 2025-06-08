import * as THREE from 'three';

document.addEventListener('DOMContentLoaded', Start);

var cena = new THREE.Scene();
var camaraPerspetiva = new THREE.PerspectiveCamera(45,4/3,0.1,100);
var renderer = new THREE.WebGLRenderer();

renderer.setSize(window.innerWidth - 15, window.innerHeight - 80);

renderer.setClearColor(0xffffff);
document.body.appendChild(renderer.domElement);

var geometriaCubo = new THREE.BoxGeometry(1,1,1);
var materialCubo = new THREE.MeshBasicMaterial({ vertexColors: true });


const vertexColorsCubo = new Float32Array([ 
    1, 0, 0, // vermelho
    0, 1, 0, // verde
    0, 0, 1, // azul
    0,0,0, // preto

    1,0,0,
    0,0,0,
    0,0,1,
    0,1,0,

    0,0,1,
    0,1,0,
    0,0,0,
    1,0,0,

    0,1,0,
    0,0,1,
    1,0,0,
    0,0,0,

    0,0,0,
    1,0,0,
    0,1,0,
    0,0,1,

    0,1,0,
    1,0,0,
    0,0,1,
    0,0,0,
    
]);

geometriaCubo.setAttribute('color', new THREE.BufferAttribute(vertexColorsCubo, 3));

var meshCubo = new THREE.Mesh(geometriaCubo, materialCubo);

meshCubo.translateZ(-6);

function loop(x){
    meshCubo.rotateY(Math.PI/180 * 1);
  
    renderer.render(cena, camaraPerspetiva);
    requestAnimationFrame(loop);
}

function Start() {
    cena.add(meshCubo);
    loop();
}