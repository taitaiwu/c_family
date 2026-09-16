import { defineConfig } from "vitepress";

export default defineConfig({
  lang: "zh-TW",
  title: "C 系列程式存檔",
  description: "課堂習題與作業存檔",
  cleanUrls: true,
  base: "/c_family",

  themeConfig: {
    nav: [
      { text: "首頁", link: "/" },
      { text: "課程", link: "/programming" },
    ],

    sidebar: [
      {
        text: "課程",
        items: [
          { text: "程式設計", link: "/programming" },
          { text: "計算機技術", link: "/practicum-in-computer" },
          { text: "離散數學", link: "/discrete-mathematics" },
          { text: "進階程式設計", link: "/advanced-programming" },
          { text: "物件導向程式設計", link: "/object-oriented-programming" },
          {
            text: "程式語言理論與實務",
            link: "/theory-and-practice-of-programming-language",
          },
        ],
      },
    ],

    socialLinks: [
      { icon: "github", link: "https://github.com/taitaiwu/c_family" },
    ],

    search: {
      provider: "local",
    },

    outline: {
      label: "本頁大綱",
    },

    docFooter: {
      prev: "上一篇",
      next: "下一篇",
    },
  },
});
