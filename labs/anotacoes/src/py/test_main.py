import unittest
from main import NotesApp
class NotesTest(unittest.TestCase):
    def test_notes_belong_to_logged_user(self) -> None:
        app = NotesApp(); app.add_user("ana", "123"); app.login("ana", "123"); app.add_note("todo", "study")
        self.assertIn("[0:todo:study]", app.show())
if __name__ == "__main__": unittest.main()
