# SGL Qt Simulator

一个基于 **Qt + SGL** 的桌面模拟器工程，用于在 PC（Windows）环境下快速开发、调试和验证嵌入式 SGL UI。

该项目的目标是：
- **在不依赖真实硬件的情况下** 调试 SGL 界面逻辑
- **最大限度复用嵌入式端代码**，做到“PC 调通 → 上板即用”
- 作为一个**可开源、可复现、可二次开发**的 SGL PC 仿真参考工程

---

## ✨ 特性（Features）

- ✅ 基于 Qt Widget 的 SGL PC 模拟器
- ✅ 使用 Qt 绘制 SGL Framebuffer
- ✅ 鼠标模拟触摸输入（Press / Release / Move）
- ✅ 定时器与事件循环对接 SGL 引擎
- ✅ 与嵌入式工程保持一致的配置方式
- ✅ 适合调试：
  - UI 布局
  - 控件事件逻辑
  - 动画 / 样式

---

## 🧱 架构说明（Architecture）

```
+-------------------+        +-------------------+
|     Qt Window     |        |   Mouse / Timer   |
|  (Widget / View) |<------>|   Event Adapter   |
+---------+---------+        +---------+---------+
          |                              |
          v                              v
+-----------------------------------------------+
|                    SGL Core                   |
|  - UI / Draw / Event / Timer                  |
+-----------------------------------------------+
          |
          v
+-------------------+
|   Framebuffer     |
|  (Qt QImage)      |
+-------------------+
```

- Qt 负责：
  - 窗口管理
  - 绘制显示
  - 鼠标事件
- SGL 负责：
  - UI 控件
  - 布局 / 动画 / 样式
  - 业务逻辑

---

## 🛠 构建环境（Build Environment）

- 操作系统：Windows 10 / 11
- Qt：5.XX
- 编译器：MinGW
- SGL：请参考官方仓库 [SGL](https://github.com/sgl-org/sgl)

---

## 🚀 快速开始（Quick Start）

1. 克隆仓库
   ```bash
   git clone https://github.com/allyzc/LCD_Emu_SGL.git
   ```

2. 使用 **Qt Creator** 打开 `.pro` 文件

3. 编译并运行

4. 启动后即可在 PC 窗口中看到 SGL UI

---

## 📄 License

This project is licensed under the **MIT License**.

It includes SGL, which is also licensed under its original license.

- SGL: https://github.com/sgl-org/sgl

> 使用、修改和分发本项目时，请保留原始版权声明。

---

## 🤝 适用人群（Who is this for）

- 嵌入式 GUI / HMI 工程师
- 使用 SGL 的物联网 / 工控开发者
- 希望在 PC 上快速验证 UI 的开发者

---

## ⭐ 致谢（Acknowledgements）

- [SGL](https://github.com/sgl-org/sgl)
- Qt Framework
