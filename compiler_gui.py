import tkinter as tk
from tkinter import ttk, filedialog, messagebox
import subprocess
import os

# Paths (adjust if needed)
PHASE3_DIR = os.path.join(os.path.dirname(__file__), 'Phase3')
INPUT_FILE = os.path.join(PHASE3_DIR, 'input.txt')
TOKENS_FILE = os.path.join(PHASE3_DIR, 'tokens.txt')
IR_FILE = os.path.join(PHASE3_DIR, 'ir.txt')
TARGET_FILE = os.path.join(PHASE3_DIR, 'targetCode.txt')
COMPILER_EXE = os.path.join(PHASE3_DIR, 'compiler.exe')

class CompilerGUI(tk.Tk):
    def __init__(self):
        super().__init__()
        self.title('C Compiler GUI')
        self.geometry('900x700')
        self.create_widgets()
        self.load_input()

    def create_widgets(self):
        # Input code area
        input_frame = ttk.LabelFrame(self, text='C Source Code (input.txt)')
        input_frame.pack(fill='both', expand=False, padx=10, pady=5)
        self.input_text = tk.Text(input_frame, height=12, font=('Consolas', 12))
        self.input_text.pack(fill='both', expand=True)

        btn_frame = tk.Frame(self)
        btn_frame.pack(fill='x', padx=10, pady=2)
        ttk.Button(btn_frame, text='Load', command=self.load_input).pack(side='left', padx=2)
        ttk.Button(btn_frame, text='Save', command=self.save_input).pack(side='left', padx=2)
        ttk.Button(btn_frame, text='Compile', command=self.compile_code).pack(side='left', padx=2)

        # Output tabs
        self.tabs = ttk.Notebook(self)
        self.tabs.pack(fill='both', expand=True, padx=10, pady=5)
        self.token_text = self._add_tab('Tokens', self.tabs)
        self.ir_text = self._add_tab('IR', self.tabs)
        self.target_text = self._add_tab('Target Code', self.tabs)
        self.error_text = self._add_tab('Errors', self.tabs)

    def _add_tab(self, title, notebook):
        frame = ttk.Frame(notebook)
        text = tk.Text(frame, wrap='none', font=('Consolas', 11))
        text.pack(fill='both', expand=True)
        notebook.add(frame, text=title)
        return text

    def load_input(self):
        try:
            with open(INPUT_FILE, 'r') as f:
                code = f.read()
            self.input_text.delete('1.0', tk.END)
            self.input_text.insert(tk.END, code)
        except Exception as e:
            messagebox.showerror('Error', f'Could not load input.txt:\n{e}')

    def save_input(self):
        try:
            code = self.input_text.get('1.0', tk.END)
            with open(INPUT_FILE, 'w') as f:
                f.write(code)
            messagebox.showinfo('Saved', 'input.txt saved successfully.')
        except Exception as e:
            messagebox.showerror('Error', f'Could not save input.txt:\n{e}')

    def compile_code(self):
        self.save_input()
        # Clear outputs
        for t in [self.token_text, self.ir_text, self.target_text, self.error_text]:
            t.delete('1.0', tk.END)
        try:
            # Run the compiler (no shell=True, capture both stdout and stderr)
            result = subprocess.run([COMPILER_EXE], cwd=PHASE3_DIR, capture_output=True, text=True)
            if result.returncode != 0:
                error_output = (result.stderr or '') + (('\n' + result.stdout) if result.stdout else '')
                self.error_text.insert(tk.END, error_output or 'Compilation failed.')
            else:
                self.error_text.insert(tk.END, result.stderr or result.stdout or 'No errors.')
        except Exception as e:
            self.error_text.insert(tk.END, f'Error running compiler.exe:\n{e}')
            return
        # Load outputs
        self._load_output(TOKENS_FILE, self.token_text)
        self._load_output(IR_FILE, self.ir_text)
        self._load_output(TARGET_FILE, self.target_text)

    def _load_output(self, path, text_widget):
        try:
            with open(path, 'r') as f:
                text_widget.insert(tk.END, f.read())
        except Exception as e:
            text_widget.insert(tk.END, f'Could not load {os.path.basename(path)}:\n{e}')

if __name__ == '__main__':
    app = CompilerGUI()
    app.mainloop()
