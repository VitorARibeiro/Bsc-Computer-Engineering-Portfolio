import * as THREE from 'three';

document.addEventListener('DOMContentLoaded', Start);

//definir Cena Camera e Renderizador
const scene = new THREE.Scene();
const camera = new THREE.PerspectiveCamera(75, window.innerWidth / window.innerHeight, 0.1, 1000);
const renderer = new THREE.WebGLRenderer();

//configurar o renderizador
renderer.setSize(window.innerWidth - 15, window.innerHeight - 80);
renderer.setClearColor(0xffffff);
document.body.appendChild(renderer.domElement);

//Para mostrar um objeto na tela, precisamos de uma geometria e um material
const geometry = new THREE.BoxGeometry(1,1,1);
const material = new THREE.MeshBasicMaterial({ color:0x0000ff });
const mesh = new THREE.Mesh(geometry, material);

function Start(){
    mesh.position.x = 0;
    mesh.position.y = 0;
    mesh.position.z = 0;
    camera.lookAt(mesh.position);
    scene.add(mesh);
    
    renderer.render(scene, camera);
}



