package ru.schoolbolt;

public class Main {

    public static void test() {
        System.out.println("Hello, World!");
    }

    public static void main(String[] args) {
        /*
	    Menu main_menu = new Menu("", true);
	    Menu file_menu = new Menu("Файл", true);
	    Menu edit_menu = new Menu("Правка", false);

        main_menu.addItem(file_menu);
        main_menu.addItem(edit_menu);

        SimpleMenuItem create = new SimpleMenuItem("Создать", Main::test);
        SimpleMenuItem open = new SimpleMenuItem("Открыть", Main::test);
        SimpleMenuItem undo = new SimpleMenuItem("Отмена", Main::test);

        file_menu.addItem(create);
        file_menu.addItem(open);

        edit_menu.addItem(undo);

        main_menu.run();
        */

        Menu main_menu = new Menu();

        Menu file_menu = main_menu.addSubmenu("Файл");
        file_menu.addItem("Создать", Main::test);
        file_menu.addItem("Открыть", Main::test);

        Menu edit_menu = main_menu.addSubmenu("Правка");
        edit_menu.addItem("Отмена", Main::test);

        main_menu.run();
    }
}
