import * as THREE from 'three';

document.addEventListener('DOMContentLoaded', Start);

var cena = new THREE.Scene();
var camara = new THREE.PerspectiveCamera(75, window.innerWidth / window.innerHeight, 0.1, 1000);
var renderer = new THREE.WebGLRenderer();

renderer.setSize(window.innerWidth - 15, window.innerHeight - 80);

renderer.setClearColor(0xffffff);
document.body.appendChild(renderer.domElement);

var geometria = new THREE.BoxGeometry(1,1,1);

var material = new THREE.MeshBasicMaterial({ color:0x00ff00 });

var mesh = new THREE.Mesh(geometria, material);

function Start() {
    cena.add(mesh);
    camara.position.set(-2,-2,-2);
    camara.lookAt(0,0,0);
    renderer.render(cena, camara);
}