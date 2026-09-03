import unittest

from main import Messaging


class MessagingTest(unittest.TestCase):
    def test_messages_are_read_once(self) -> None:
        messaging = Messaging()
        messaging.add_user("david")
        messaging.add_user("celia")
        messaging.send("david", "celia", "hello")
        self.assertEqual("david:hello", messaging.inbox("celia"))
        self.assertEqual("- empty -", messaging.inbox("celia"))


if __name__ == "__main__":
    unittest.main()
