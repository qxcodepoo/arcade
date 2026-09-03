import unittest

from main import WhatsApp


class WhatsAppTest(unittest.TestCase):
    def test_messages_are_unread_per_member_and_sender_does_not_receive_own(self) -> None:
        app = WhatsApp()
        for name in ("goku", "sara"):
            app.add_user(name)
        group = app.create("goku", "friends")
        app.invite("goku", "sara", group.identifier)
        app.send("goku", group.identifier, "hello")
        self.assertEqual(1, group.unread_count("sara"))
        self.assertEqual("hello", app.read("sara", group.identifier).split(": ", 1)[1])
        self.assertEqual(0, group.unread_count("sara"))


if __name__ == "__main__":
    unittest.main()
