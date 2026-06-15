<<<<<<< HEAD
document.addEventListener("DOMContentLoaded", () => {
  const toggleBtn = document.getElementById("themeToggle");
  const body = document.body;

  if (!toggleBtn) return;
  const savedTheme = localStorage.getItem("theme");

  if (savedTheme) {
    body.classList.add(savedTheme);
    toggleBtn.textContent = savedTheme === "dark" ? "☀️" : "🌙";
  } else {
    body.classList.add("dark"); // theme de base
  }

  // Changement de thème
  toggleBtn.addEventListener("click", () => {
    if (body.classList.contains("dark")) {
      body.classList.replace("dark", "light");
      toggleBtn.textContent = "🌙";
      localStorage.setItem("theme", "light");
    } else {
      body.classList.replace("light", "dark");
      toggleBtn.textContent = "☀️";
      localStorage.setItem("theme", "dark");
    }
  });
});
//Changement de l'annee automatique
document.addEventListener("DOMContentLoaded", () => {
  document.getElementById("year").textContent =
    new Date().getFullYear();
});
=======
document.addEventListener("DOMContentLoaded", () => {
  const toggleBtn = document.getElementById("themeToggle");
  const body = document.body;

  if (!toggleBtn) return;
  const savedTheme = localStorage.getItem("theme");

  if (savedTheme) {
    body.classList.add(savedTheme);
    toggleBtn.textContent = savedTheme === "dark" ? "☀️" : "🌙";
  } else {
    body.classList.add("dark"); // theme de base
  }

  // Changement de thème
  toggleBtn.addEventListener("click", () => {
    if (body.classList.contains("dark")) {
      body.classList.replace("dark", "light");
      toggleBtn.textContent = "🌙";
      localStorage.setItem("theme", "light");
    } else {
      body.classList.replace("light", "dark");
      toggleBtn.textContent = "☀️";
      localStorage.setItem("theme", "dark");
    }
  });
});
//Changement de l'annee automatique
document.addEventListener("DOMContentLoaded", () => {
  document.getElementById("year").textContent =
    new Date().getFullYear();
});
>>>>>>> 022af3dc43f29967a064dbbe7d5b93d3bd0eefe7
