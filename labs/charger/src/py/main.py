from enum import Enum


CANNOT_TURN_ON_MSG: str = "fail: cannot turn on"
NOTEBOOK_OFF_MSG: str = "fail: notebook is off"
BATTERY_DISCHARGED_MSG: str = "fail: battery discharged"
CHARGER_ALREADY_CONNECTED_MSG: str = "fail: charger is already connected"
NO_BATTERY_MSG: str = "fail: no battery"
NO_CHARGER_MSG: str = "fail: no charger"
INVALID_COMMAND_MSG: str = "fail: invalid command"


class UseResult(Enum):
    OK = 0
    NOTEBOOK_OFF = 1
    DISCHARGED = 2


class Battery:
    def __init__(self, capacity: int) -> None:
        self.__capacity: int = capacity
        self.__charge: int = capacity

    def getCapacity(self) -> int:
        return self.__capacity

    def getCharge(self) -> int:
        return self.__charge

    def consume(self, minutes: int) -> bool:
        if self.__charge < minutes:
            self.__charge = 0
            return False
        self.__charge -= minutes
        return True

    def recharge(self, amount: int) -> None:
        self.__charge = min(self.__capacity, self.__charge + amount)

    def __str__(self) -> str:
        return f"{self.__charge}/{self.__capacity}"


class Charger:
    def __init__(self, power: int) -> None:
        self.__power: int = power

    def getPower(self) -> int:
        return self.__power

    def __str__(self) -> str:
        return f"{self.__power}W"


class Notebook:
    def __init__(self) -> None:
        self.__inUse: bool = False
        self.__usage: int = 0
        self.__battery: Battery | None = None
        self.__charger: Charger | None = None

    def turnOn(self) -> bool:
        if self.__charger is None and (
            self.__battery is None or self.__battery.getCharge() == 0
        ):
            return False
        self.__inUse = True
        return True

    def turnOff(self) -> None:
        self.__inUse = False
        self.__usage = 0

    def use(self, minutes: int) -> UseResult:
        if not self.__inUse:
            return UseResult.NOTEBOOK_OFF

        if self.__battery is None:
            self.__usage += minutes
            return UseResult.OK

        if self.__charger is not None:
            self.__usage += minutes
            self.__battery.recharge(self.__charger.getPower() * minutes)
            return UseResult.OK

        if self.__battery.consume(minutes):
            self.__usage += minutes
            return UseResult.OK

        self.__inUse = False
        return UseResult.DISCHARGED

    def setBattery(self, battery: Battery) -> None:
        self.__battery = battery

    def removeBattery(self) -> Battery | None:
        if self.__battery is None:
            return None
        removedBattery: Battery = self.__battery
        self.__battery = None
        if self.__charger is None and self.__inUse:
            self.turnOff()
        return removedBattery

    def setCharger(self, charger: Charger) -> bool:
        if self.__charger is not None:
            return False
        self.__charger = charger
        return True

    def removeCharger(self) -> Charger | None:
        if self.__charger is None:
            return None
        removedCharger: Charger = self.__charger
        self.__charger = None
        if self.__battery is None or self.__battery.getCharge() == 0:
            if self.__inUse:
                self.turnOff()
        return removedCharger

    def __str__(self) -> str:
        status: str = "on" if self.__inUse else "off"
        if self.__inUse:
            status += f" for {self.__usage} min"
        if self.__charger is not None:
            status += f", Charger {self.__charger}"
        if self.__battery is not None:
            status += f", Battery {self.__battery}"
        return f"Notebook: {status}"


def printUseResult(result: UseResult) -> None:
    if result == UseResult.NOTEBOOK_OFF:
        print(NOTEBOOK_OFF_MSG)
    elif result == UseResult.DISCHARGED:
        print(BATTERY_DISCHARGED_MSG)


def main() -> None:
    notebook: Notebook = Notebook()

    while True:
        line: str = input()
        print("$" + line)

        match line.split():
            case ["end"]:
                break
            case ["show"]:
                print(notebook)
            case ["turnOn"]:
                if not notebook.turnOn():
                    print(CANNOT_TURN_ON_MSG)
            case ["turnOff"]:
                notebook.turnOff()
            case ["use", minutes]:
                printUseResult(notebook.use(int(minutes)))
            case ["setBattery", capacity]:
                notebook.setBattery(Battery(int(capacity)))
            case ["removeBattery"]:
                battery: Battery | None = notebook.removeBattery()
                if battery is None:
                    print(NO_BATTERY_MSG)
                else:
                    print(f"Removed {battery}")
            case ["setCharger", power]:
                if not notebook.setCharger(Charger(int(power))):
                    print(CHARGER_ALREADY_CONNECTED_MSG)
            case ["removeCharger"]:
                charger: Charger | None = notebook.removeCharger()
                if charger is None:
                    print(NO_CHARGER_MSG)
                else:
                    print(f"Removed {charger}")
            case _:
                print(INVALID_COMMAND_MSG)


if __name__ == "__main__":
    main()
