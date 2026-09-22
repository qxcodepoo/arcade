INVALID_HOUR_MSG: str = "fail: invalid hour"
INVALID_MINUTE_MSG: str = "fail: invalid minute"
INVALID_COMMAND_MSG: str = "fail: invalid command"

class Time:
    MIN_VALUE: int = 0
    MAX_HOUR: int = 23
    MAX_MINUTE: int = 59
    MID_DAY: int = 12

    def __init__(self) -> None:
        self.__hour: int = Time.MIN_VALUE
        self.__minute: int = Time.MIN_VALUE
        self.is_24h_mode: bool = True

    def get_hour(self) -> int:
        hour: int = self.__hour
        if self.is_24h_mode:
            return hour
        
        if hour == 0:
            return 12
        if hour > 12:
            return hour - 12
        return hour
    
    def get_minute(self) -> int:
        return self.__minute

    def set_hour(self, hour: int) -> bool:
        if hour < Time.MIN_VALUE:
            return False
        if hour > Time.MAX_HOUR:
            return False
        self.__hour = hour
        return True

    def set_minute(self, minute: int) -> bool:
        if minute < Time.MIN_VALUE:
            return False
        if minute > Time.MAX_MINUTE:
            return False

        self.__minute = minute
        return True

    def next_minute(self) -> None:
        self.__minute += 1
        if self.__minute <= Time.MAX_MINUTE:
            return
        self.__minute = Time.MIN_VALUE
        self.__hour += 1
        if self.__hour <= Time.MAX_HOUR:
            return

        self.__hour = Time.MIN_VALUE

    def toggle_mode(self) -> None:
        self.is_24h_mode = not self.is_24h_mode

    def is_am(self) -> bool:
        return self.__hour < self.MID_DAY

    def __str__(self) -> str:
        if self.is_24h_mode:
            return f"24h -> {self.__hour:02d}:{self.__minute:02d}"
        hour = self.get_hour()
        period: str = "AM" if self.is_am() else "PM"
        return f"12h -> {hour:02d}:{self.__minute:02d} {period}"


def main() -> None:
    time: Time = Time()

    while True:
        line: str = input()
        print("$" + line)

        match line.split():
            case ["end"]:
                break
            case ["show"]:
                print(time)
            case ["init", hour, minute]:
                time = Time()
                time.set_hour(int(hour))
                time.set_minute(int(minute))
            case ["set", hour, minute]:
                if not time.set_hour(int(hour)):
                    print(INVALID_HOUR_MSG)
                if not time.set_minute(int(minute)):
                    print(INVALID_MINUTE_MSG)
            case ["next"]:
                time.next_minute()
            case ["mode"]:
                time.toggle_mode()
            case _:
                print(INVALID_COMMAND_MSG)


if __name__ == "__main__":
    main()
