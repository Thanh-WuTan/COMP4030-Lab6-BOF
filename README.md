# COMP4030 - Buffer Overflow Exploitation Lab

## Lab Description

In this lab, you will learn how to exploit a basic binary that contains a buffer overflow vulnerability.

This lab will guide you through the process of identifying the vulnerability, understanding modern binary protections, and crafting an exploit script.

## Objectives

- Understand common binary security protections such as ASLR, PIE, and NX.
- Identify buffer overflow vulnerabilities in simple programs.
- Use GDB (GNU Debugger) to analyze and debug binaries.
- Use Python and the pwntools library to craft automated exploit scripts.

## Setup Instructions
In this lab, the goal of each challenge is to have the flag printed out.

To simulate this, you will create a simple flag file on your machine that can be accessed by the challenge binaries.

Use the following commands:
```bash
sudo sh -c 'echo "FAKEFLAG{this_is_your_test_flag}" > /flag'
sudo chmod 644 /flag
```

## Student Deliverables

Please submit to Canvas:

- A **single PDF report** covering **all four challenges**, containing:
  - A detailed **step-by-step explanation** of how each binary was exploited:
    - How you identified the vulnerability.
    - How you calculated the offset to overwrite the return address.
    - How you determined binary protections (ASLR, PIE, NX) and bypassed them.
    - How you crafted the payload.
    - How you used pwntools to automate the exploit.
  - Output logs or **screenshots** showing successful exploitation (e.g., flag printed).
  
- A **ZIP file** containing:
  - `ret2shellcode.py`
  - `ret2win.py`
  - `trigger_win.py`
  - `stack_canary.py`
  - The PDF report: `report.pdf`


## Acknowledgments
This lab is inspired by the excellent materials from [pwn.college](https://pwn.college).

Special thanks to the amazing pwn.college team for their work on the dojo exercises and for making high-quality CTF-style training accessible to everyone.