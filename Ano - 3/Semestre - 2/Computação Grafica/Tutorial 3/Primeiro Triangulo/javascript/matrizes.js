/**
 * @param {number} x - The x translation value
 * @param {number} y - The y translation value
 * @param {number} z - The z translation value
 * @param {number} angulo - The angle in degrees
 */

function CriarMatrizTranslacao(x, y, z) {
    return [
        [1, 0, 0, x],
        [0, 1, 0, y],
        [0, 0, 1, z],
        [0, 0, 0, 1]
    ]; 
}

function CriarMatrizEscala(x, y, z) {
    return [
        [x, 0, 0, 0],
        [0, y, 0, 0],
        [0, 0, z, 0],
        [0, 0, 0, 1]
    ]; 
}

function CriarMatrizRotacaoX(angulo) {
    const rad = angulo * Math.PI / 180;
    return [
        [1, 0, 0, 0],
        [0, Math.cos(rad), -Math.sin(rad), 0],
        [0, Math.sin(rad), Math.cos(rad), 0],
        [0, 0, 0, 1]
    ]; 
}

function CriarMatrizRotacaoY(angulo) {
    const rad = angulo * Math.PI / 180;
    return [
        [Math.cos(rad), 0, Math.sin(rad), 0],
        [0, 1, 0, 0],
        [-Math.sin(rad), 0, Math.cos(rad), 0],
        [0, 0, 0, 1]
    ]; 
}

function CriarMatrizRotacaoZ(angulo) {
    const rad = angulo * Math.PI / 180;
    return [
        [Math.cos(rad), -Math.sin(rad), 0, 0],
        [Math.sin(rad), Math.cos(rad), 0, 0],
        [0, 0, 1, 0],
        [0, 0, 0, 1]
    ]; 
}