import random
import subprocess
import argparse

def generate_test_data(count, output_file):
    """Генерирует случайные числа и записывает их в файл."""
    with open(output_file, "w") as f:
        for _ in range(count):
            a = random.randint(1, 100)
            b = random.randint(0, 5)  # 0 будет в 20% случаев
            f.write(f"{a} {b}\n")
    print(f"[+] Generated {count} test cases in {output_file}")

def run_program(input_file, program_path="./main"):
    """Запускает C++ программу с входными данными."""
    try:
        result = subprocess.run(
            [program_path, input_file],
            capture_output=True,
            text=True,
            check=True
        )
        print("[+] Program output:")
        print(result.stdout)
    except subprocess.CalledProcessError as e:
        print("[-] Program crashed:")
        print(e.stderr)

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Test data generator and runner")
    parser.add_argument("--count", type=int, default=10, help="Number of test cases")
    parser.add_argument("--output", type=str, default="test_data.txt", help="Output file")
    parser.add_argument("--program", type=str, default="./main", help="C++ executable path")
    args = parser.parse_args()

    generate_test_data(args.count, args.output)
    run_program(args.output, args.program)