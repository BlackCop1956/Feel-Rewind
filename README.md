
# 📻 FeelRewind – A Nostalgic Decade Radio

**FeelRewind** is a retro-themed web experience that lets you relive iconic decades through the lens of music, culture, and memories. It fuses a vintage user interface with dynamic decade-specific content — including Bollywood classics, historical highlights, and legendary figures — all powered by a custom C++ backend and a modern JavaScript frontend.

---

## 💡 Inspiration

Nostalgia has a unique power — it brings back emotions, memories, and moments long forgotten. With FeelRewind, we wanted to build a digital time capsule that celebrates the essence of each decade, allowing users to experience the soul of the '60s through the 2010s in one immersive radio interface.

---

## 🎯 What It Does

- 🎵 **Streams handpicked Bollywood hits** from six different decades.
- 🖼️ **Displays album-style song thumbnails** and track titles.
- 💡 **Shares a fun fact and major news event** from the selected decade.
- 🌟 **Showcases an influential figure** with image and brief description.
- 🎛️ **Interactive and animated UI** that evolves with the user's selection.

---

## 🛠️ How We Built It

- **Frontend**: HTML5, CSS3 (with retro visual theme), and JavaScript for interactivity.
- **Backend**: Built entirely in **C++**, using:
  - [`httplib`](https://github.com/yhirose/cpp-httplib) – lightweight HTTP server
  - [`nlohmann/json`](https://github.com/nlohmann/json) – JSON parsing
- The backend serves curated song data, fun facts, news snippets, and cultural icons based on the selected decade.
- Frontend communicates with the backend via `POST` requests and dynamically updates the UI.

---

## 🚧 Challenges We Faced

- ✅ Hosting a web server using **pure C++** without a traditional web framework.
- 🎯 Achieving **CORS-compliant API communication** between the frontend and the local server.
- 🖼️ Coordinating multimedia assets like thumbnails, audio, and images with precise path mapping.
- 💻 Designing a **responsive, retro-inspired UI** while keeping it clean and accessible.

---

## 🏆 Accomplishments We're Proud Of

- Built a **full-stack multimedia experience** combining low-level backend development with polished frontend UI.
- Designed an elegant, nostalgic theme that connects users emotionally.
- Developed an **API server from scratch** using just C++ libraries.
- Delivered a smooth and engaging user journey — from welcome screen to radio play.

---

## 📘 What We Learned

- Implementing backend logic in **C++ for web use cases** — including JSON and HTTP.
- Managing **asynchronous media and DOM updates** in JavaScript.
- Blending content (music, culture, visuals) for immersive storytelling.
- Designing with purpose — every detail from font to color evoking a vintage vibe.

---

## 🚀 What’s Next

- 🔗 **YouTube API integration** to dynamically fetch videos and thumbnails.
- 📱 **Mobile-first responsive design** and PWA support.
- ❤️ User **login and personalized playlists**.
- 🔍 **Search and filter** through decades, songs, or artists.
- ☁️ Hosting backend APIs to make the project shareable and scalable.

---

## 🖼️ Project Preview

![Retro Poster](./A_retro-styled,_graphic_design_poster_for_a_projec.png)

---

## 📂 Project Structure

```
FeelRewind/
├── FeelRewind.html         # Frontend: UI, JS logic, audio controls
├── radioServer.cpp         # Backend: API server, decade logic
├── audio/                  # MP3 tracks for each decade
├── thumbnails/             # Song thumbnails
├── influentials/           # Images of notable personalities
├── style.css (inline)      # Retro-themed styles
└── README.md               # You are here!
```

---

## 🧪 Running the Project Locally

1. **Compile and start the C++ backend server**:
   ```bash
   g++ radioServer.cpp -o server
   ./server
   ```

2. **Open the frontend**:
   Just open `FeelRewind.html` in your browser (ensure media files are in place).

---

## 🏁 Built For

> **OSDC Hack 2025**  
> First-time submission by **Team FeelRewind**  
> Bringing decades of stories back to life 🎙️
