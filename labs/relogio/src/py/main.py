INVALID_HOUR_MSG: str = "fail: invalid hour"
INVALID_MINUTE_MSG: str = "fail: invalid minute"
INVALID_COMMAND_MSG: str = "fail: invalid command"


class Time:
    MIN_VALUE: int = 0
    MAX_HOUR: int = 23
    MAX_MINUTE: int = 59

    def __init__(self, hour: int, minute: int) -> None:
        self.__hour: int = Time.MIN_VALUE
        self.__minute: int = Time.MIN_VALUE
        self.__is_am_pm: bool = False
        self.setHour(hour)
        self.setMinute(minute)

    def getHour(self) -> int:
        return self.__hour

    def getMinute(self) -> int:
        return self.__minute

    def isAmPm(self) -> bool:
        return self.__is_am_pm

    def setHour(self, hour: int) -> bool:
        if hour < Time.MIN_VALUE:
            return False
        if hour > Time.MAX_HOUR:
            return False

        self.__hour = hour
        return True

    def setMinute(self, minute: int) -> bool:
        if minute < Time.MIN_VALUE:
            return False
        if minute > Time.MAX_MINUTE:
            return False

        self.__minute = minute
        return True

    def nextMinute(self) -> None:
        self.__minute += 1
        if self.__minute <= Time.MAX_MINUTE:
            return

        self.__minute = Time.MIN_VALUE
        self.__hour += 1
        if self.__hour <= Time.MAX_HOUR:
            return

        self.__hour = Time.MIN_VALUE

    def toggleMode(self) -> None:
        self.__is_am_pm = not self.__is_am_pm

    def __str__(self) -> str:
        if not self.__is_am_pm:
            return f"24h: {self.__hour:02d}:{self.__minute:02d}"

        period: str = "AM"
        if self.__hour >= 12:
            period = "PM"

        hour: int = self.__hour % 12
        if hour == 0:
            hour = 12

        return f"AM/PM: {hour:02d}:{self.__minute:02d} {period}"


def main() -> None:
    time: Time = Time(0, 0)

    while True:
        line: str = input()
        print("$" + line)

        match line.split():
            case ["end"]:
                break
            case ["show"]:
                print(time)
            case ["init", hour, minute]:
                time = Time(int(hour), int(minute))
            case ["set", hour, minute]:
                if not time.setHour(int(hour)):
                    print(INVALID_HOUR_MSG)
                if not time.setMinute(int(minute)):
                    print(INVALID_MINUTE_MSG)
            case ["next"]:
                time.nextMinute()
            case ["mode"]:
                time.toggleMode()
            case _:
                print(INVALID_COMMAND_MSG)


if __name__ == "__main__":
    main()
