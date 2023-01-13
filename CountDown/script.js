const countdownEl = document.querySelector(".countdown");

const createCountDownParts = () => {
  ["days", "hours", "minutes", "seconds"].forEach((part) => {
    const partEl = document.createElement("div");
    partEl.classList.add("part", part);
    const textEl = document.createElement("div");
    textEl.classList.add("text");
    textEl.innerText = part;
    const numberEl = document.createElement("div");
    numberEl.classList.add("number");
    numberEl.innerText = 0;
    partEl.append(numberEl, textEl);
    countdownEl.append(partEl);
  });
};

const countdownFunction = () => {
  const currentDate = new Date();
  const targetDate = new Date(countdownEl.getAttribute("date-time"));
  if (currentDate > targetDate) return clearInterval(countdownLoopId);
  const remaining = getRemaining(targetDate, currentDate);
  console.log(remaining)
  Object.entries(remaining).forEach(([part, value]) => {
    const partEl = countdownEl.querySelector(`.part.${part} .number`);
    partEl.style.setProperty("--value", value);
    partEl.innerText = value;
  });
};

const getRemaining = (target, now) => {
  let seconds = Math.floor((target - now) / 1000);
  let minutes = Math.floor(seconds / 60);
  let hours = Math.floor(minutes / 60);
  let days = Math.floor(hours / 24);
  hours = hours - days * 24;
  minutes = minutes - days * 24 * 60 - hours * 60;
  seconds = seconds - days * 24 * 60 * 60 - hours * 60 * 60 - minutes * 60;
  return { days, hours, minutes, seconds };
};

createCountDownParts();
const countdownLoopId =setInterval(countdownFunction, 1000);
