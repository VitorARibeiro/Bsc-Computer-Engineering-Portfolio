import * as THREE from 'three';

document.addEventListener('DOMContentLoaded', Start);

var cena = new THREE.Scene();
var camara = new THREE.OrthographicCamera(-1,1,1,-1,-10,10);
var renderer = new THREE.WebGLRenderer();

renderer.setSize(window.innerWidth - 15, window.innerHeight - 80);

renderer.setClearColor(0xffffff);
document.body.appendChild(renderer.domElement);

var geometria = new THREE.BufferGeometry();
var vertices = new Float32Array([
    -0.5 , -0-5, 0.0,
    0.5 , -0.5, 0.0,
    0.0 , 0.5, 0.0
])
const cores = new Float32Array([
    1.0, 0.0, 0.0,
    0.0, 1.0, 0.0,
    0.0, 0.0, 1.0
])

geometria.setAttribute('position', new THREE.BufferAttribute(vertices, 3));
geometria.setAttribute('color', new THREE.BufferAttribute(cores, 3));

var material = new THREE.MeshBasicMaterial({ vertexColors: true });

var mesh = new THREE.Mesh(geometria, material);

mesh.translateX(0.5);
mesh.translateY(0.5);

mesh.scale.set(0.25,0.25,0.25);


function loop(x){
    mesh.rotateX(Math.PI/180 * 1);
  
    renderer.render(cena, camara);
    requestAnimationFrame(loop);
}

function Start() {
    cena.add(mesh);
    loop();
}