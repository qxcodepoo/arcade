const val INVALID_HOUR_MSG: String = "fail: invalid hour"
const val INVALID_MINUTE_MSG: String = "fail: invalid minute"
const val INVALID_COMMAND_MSG: String = "fail: invalid command"

class Time {
    companion object {
        const val MIN_VALUE: Int = 0
        const val MAX_HOUR: Int = 23
        const val MAX_MINUTE: Int = 59
        const val MID_DAY: Int = 12
    }

    private var hour: Int = MIN_VALUE
    private var minute: Int = MIN_VALUE
    private var is24hMode: Boolean = true

    fun getHour(): Int {
        if (is24hMode) {
            return hour
        }
        if (hour == MIN_VALUE || hour == MID_DAY) {
            return MID_DAY
        }
        return if (hour > MID_DAY) hour - MID_DAY else hour
    }

    fun getMinute(): Int = minute

    fun isAm(): Boolean = hour < MID_DAY

    fun setHour(hour: Int): Boolean {
        if (hour !in MIN_VALUE..MAX_HOUR) {
            return false
        }
        this.hour = hour
        return true
    }

    fun setMinute(minute: Int): Boolean {
        if (minute !in MIN_VALUE..MAX_MINUTE) {
            return false
        }
        this.minute = minute
        return true
    }

    fun nextMinute(): Unit {
        if (minute < MAX_MINUTE) {
            minute++
            return
        }
        minute = MIN_VALUE
        hour = if (hour < MAX_HOUR) hour + 1 else MIN_VALUE
    }

    fun toggleMode(): Unit {
        is24hMode = !is24hMode
    }

    override fun toString(): String {
        val hourText: String = getHour().toString().padStart(2, '0')
        val minuteText: String = minute.toString().padStart(2, '0')
        if (is24hMode) {
            return "24h -> $hourText:$minuteText"
        }
        val period: String = if (isAm()) "AM" else "PM"
        return "12h -> $hourText:$minuteText $period"
    }
}

fun main(): Unit {
    var time: Time = Time()

    while (true) {
        val line: String = readlnOrNull() ?: break
        println("\$$line")

        val parts: List<String> = line.trim().split(Regex("\\s+")).filter { it.isNotEmpty() }
        when {
            parts == listOf("end") -> break
            parts == listOf("show") -> println(time)
            parts.size == 3 && parts[0] == "init" -> {
                time = Time()
                time.setHour(parts[1].toInt())
                time.setMinute(parts[2].toInt())
            }
            parts.size == 3 && parts[0] == "set" -> {
                if (!time.setHour(parts[1].toInt())) {
                    println(INVALID_HOUR_MSG)
                }
                if (!time.setMinute(parts[2].toInt())) {
                    println(INVALID_MINUTE_MSG)
                }
            }
            parts == listOf("next") -> time.nextMinute()
            parts == listOf("mode") -> time.toggleMode()
            else -> println(INVALID_COMMAND_MSG)
        }
    }
}
