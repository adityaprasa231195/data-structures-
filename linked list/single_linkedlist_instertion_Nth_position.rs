struct ListNode {
    data: i32,
    next: Option<Box<ListNode>>,
}

fn insert_at_nth(head: &mut Option<Box<ListNode>>, value: i32, position: usize) {
    if position == 0 {
        println!("Invalid position");
        return;
    }

    let mut current = head;

    for _ in 1..position {
        match current {
            Some(node) => current = &mut node.next,
            None => {
                println!("Invalid position");
                return;
            }
        }
    }

    let new_node = Box::new(ListNode {
        data: value,
        next: current.take(),
    });

    *current = Some(new_node);
}

fn print_list(head: &Option<Box<ListNode>>) {
    let mut current = head.as_ref();

    while let Some(node) = current {
        print!("{} ", node.data);
        current = node.next.as_ref();
    }

    println!();
}

fn main() {
    let mut head = Some(Box::new(ListNode {
        data: 10,
        next: Some(Box::new(ListNode {
            data: 20,
            next: Some(Box::new(ListNode {
                data: 30,
                next: None,
            })),
        })),
    }));

    print_list(&head);

    insert_at_nth(&mut head, 5, 1);
    insert_at_nth(&mut head, 15, 3);
    insert_at_nth(&mut head, 40, 6);

    print_list(&head);
}