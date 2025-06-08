import * as THREE from 'three';

document.addEventListener('DOMContentLoaded', Start);

var cena = new THREE.Scene();
var camaraPerspetiva = new THREE.PerspectiveCamera(45,4/3,0.1,100);
var renderer = new THREE.WebGLRenderer();

renderer.setSize(window.innerWidth - 15, window.innerHeight - 80);

renderer.setClearColor(0xffffff);
document.body.appendChild(renderer.domElement);


var textura = new THREE.TextureLoader().load('./Images/boxImage.jpg');
var materialTextura = new THREE.MeshBasicMaterial({ map: textura });

var geometriaCubo = new THREE.BoxGeometry(1,1,1);

var uvAttribute = geometriaCubo.getAttribute('uv');

uvAttribute.setXY(0,0,0);
uvAttribute.setXY(1,1/3,0);
uvAttribute.setXY(2,1/3,1/3);
uvAttribute.setXY(3,0,1/3);

uvAttribute.setXY(4,1/3,0);
uvAttribute.setXY(5,2/3,0);
uvAttribute.setXY(6,2/3,1/3);
uvAttribute.setXY(7,1/3,1/3);

uvAttribute.setXY(8,2/3,0);
uvAttribute.setXY(9,1,0);
uvAttribute.setXY(10,1,1/3);
uvAttribute.setXY(11,2/3,1/3);

uvAttribute.setXY(12,0,1/3);
uvAttribute.setXY(13,1/3,1/3);
uvAttribute.setXY(14,1/3,2/3);
uvAttribute.setXY(15,0,2/3);

uvAttribute.setXY(16,1/3,1/3);
uvAttribute.setXY(17,2/3,1/3);
uvAttribute.setXY(18,2/3,2/3);
uvAttribute.setXY(19,1/3,2/3);

uvAttribute.setXY(20,2/3,1/3);
uvAttribute.setXY(21,1,1/3);
uvAttribute.setXY(22,1,2/3);
uvAttribute.setXY(23,2/3,2/3);

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

var meshCubo = new THREE.Mesh(geometriaCubo, materialTextura);

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