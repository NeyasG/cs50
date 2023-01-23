// Slider functionality from https://youtu.be/dzqDU9efnnk

const container = document.querySelector('.container-slider');
document.querySelector('.slider').addEventListener('input', (e) => {
  container.style.setProperty('--position', `${e.target.value}%`);
});