from student import CarAdp

class Shell:
    def __init__(self):
        self.adp: CarAdp = CarAdp()

    def help(self) -> str:
        return "show; enter; leave; fuel <qtd>; drive <dist>"

    def process_line(self, line: str) -> None:
        args: list[str] = line.split(" ")
        if args[0] == "help":
            print(self.help())
        elif args[0] == "show":
            print(self.adp.show());
        elif args[0] == "enter":
            self.adp.enter()
        elif args[0] == "leave":
            self.adp.leave()
        elif args[0] == "fuel":
            self.adp.fuel(int(args[1]))
        elif args[0] == "drive":
            self.adp.drive(int(args[1]))
        else:
            print("fail: comando invalido")

    def run(self) -> None:
        while True:
            print("$", end="")
            line = input()
            print(line)
            if line == "end":
                break
            self.process_line(line)

Shell().run()