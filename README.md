# Shout-Out
C++ console program of a simple short message exchange between existing users. Basically a very simple, baby version of Twitter. All accounts and their data are preserved outside of program runtime via 3 files: "Accounts.dat", "FollowList.dat", "Shouts.dat".

Upon startup, users may login or create an account. Accounts and their passwords are stored in the "Accounts.dat" file. The format is as follows:

Username<br>
Password<br>

If a user creates an account, they are immediately directed to their main page.

When logging in, the user is prompted for their username, then their password. If the username isn't found, or the entered password is incorrect, the user may retry their login.

When successfully logged in, users may:<br>

1)Post a shout.<br>
2)Send a private message (Whisper)<br>
3)View their shout page (Both public shouts and private shouts sent to them, private shouts are accompanied by the sender's username)<br>
4)View who they are following. <br>

  From this "following" page, they may:<br>
    Select someone they are following, and view that user's shout page.<br>
    Follow another user<br>
    Unfollow a user<br>

5)View who follows them.<br>

  From this "follows" page, they may:<br>
    Select a follower, and view that user's shout page.<br>


The "FollowList.dat" file stores a user and who they follow in the following format:

Username<br>
User that this username follows<br>

The "Shouts.dat" file stores all shouts in the following format:

Public or Private (1 is public, 2 is private)<br>
Username that posted the shout<br>
Target of the shout (0 is public, otherwise the target username is written)<br>
Content of the shout <br>
