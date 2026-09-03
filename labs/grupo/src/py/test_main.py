import unittest

from main import Messenger


class MessengerTest(unittest.TestCase):
    def test_group_and_talk_share_the_chat_contract(self) -> None:
        app = Messenger()
        app.add_user("goku")
        app.add_user("sara")
        app.create_group("goku", "family")
        app.chat("family").invite("goku", "sara")
        app.chat("family").send("goku", "hello")
        self.assertEqual("hello", app.chat("family").read("sara")[0].text)
        app.create_talk("goku", "sara")
        app.chat("goku-sara").send("sara", "hi")
        self.assertEqual("hi", app.chat("goku-sara").read("goku")[0].text)


if __name__ == "__main__":
    unittest.main()
