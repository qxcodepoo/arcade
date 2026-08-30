import os
from typing import List, Dict, Tuple

lines = open("solver.cpp").read().split("\n")
output: List[str] = []

output.append("@startuml")
output.append('skinparam defaultFontName "JetBrains Mono Medium"')

for line in lines:
    if line.startswith("    // +") or line.startswith("    // -") or line.startswith("    // ~") or line.startswith("    // __"):
        output.append(line.replace("    // ", "    "))
        output.append("    '")
    elif line.startswith("    // "):
        output.append(line.replace("    // ", "    "))
    elif line.startswith("//!"):
        continue
    elif line.startswith("// class"):
        output.append(line.replace("// ", ""))
        output.append("    '")
    elif line.startswith("// "):
        output.append(line.replace("// ", ""))
    elif line.startswith("};"):
        output.append("}")
        output.append("")

output.append("@enduml")

print("\n".join(output))